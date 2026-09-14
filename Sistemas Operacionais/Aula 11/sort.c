/*
 * Aula 11 - Implementação simplificada do utilitário sort usando as chamadas de sistema
 * open/read/close: lê cada arquivo inteiro, ordena as linhas lexicograficamente e as imprime.
 *
 * Uso: sort [--help] [--version] [arquivos...]   ("-" ou nenhum arquivo = terminal)
 */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* Versão do programa. */
#define VERSION_MAJOR 1
#define VERSION_MINOR 0

/* Argumentos do programa. */
static char *const *filenames; /* Arquivos a ordenar.   */
static int nfiles = 0;         /* Quantidade de arquivos. */

/* Lê todo o conteúdo de fd para um buffer terminado em '\0'. Retorna NULL em caso de erro. */
static char *read_all(int fd, size_t *length) {
    size_t capacity = BUFSIZ;
    size_t size = 0;
    char *data = malloc(capacity + 1);
    if (data == NULL)
        return NULL;

    for (;;) {
        if (size == capacity) {
            capacity *= 2;
            char *bigger = realloc(data, capacity + 1);
            if (bigger == NULL) {
                free(data);
                return NULL;
            }
            data = bigger;
        }

        ssize_t nread = read(fd, data + size, capacity - size);
        if (nread < 0) {
            free(data);
            return NULL;
        }
        if (nread == 0)
            break;
        size += (size_t) nread;
    }

    data[size] = '\0';
    *length = size;
    return data;
}

static int compare_lines(const void *a, const void *b) {
    return strcmp(*(const char *const *) a, *(const char *const *) b);
}

/* Ordena e imprime as linhas do arquivo. */
static void sort(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "sort: cannot open %s: %s\n", filename, strerror(errno));
        return;
    }

    size_t length;
    char *data = read_all(fd, &length);
    close(fd);
    if (data == NULL) {
        fprintf(stderr, "sort: cannot read %s\n", filename);
        return;
    }

    // Conta as linhas (a última pode não terminar em '\n').
    size_t lines = 0;
    for (size_t i = 0; i < length; i++)
        if (data[i] == '\n')
            lines++;
    if (length > 0 && data[length - 1] != '\n')
        lines++;

    char **line_ptrs = malloc((lines ? lines : 1) * sizeof(char *));
    if (line_ptrs == NULL) {
        free(data);
        return;
    }

    // Divide o buffer em linhas, trocando '\n' por '\0'.
    size_t current = 0;
    char *start = data;
    for (size_t i = 0; i < length; i++) {
        if (data[i] == '\n') {
            data[i] = '\0';
            line_ptrs[current++] = start;
            start = data + i + 1;
        }
    }
    if (current < lines)
        line_ptrs[current++] = start;

    qsort(line_ptrs, lines, sizeof(char *), compare_lines);

    for (size_t i = 0; i < lines; i++)
        printf("%s\n", line_ptrs[i]);

    free(line_ptrs);
    free(data);
}

static void version(void) {
    printf("sort (FEI) %d.%d\n", VERSION_MAJOR, VERSION_MINOR);
    exit(EXIT_SUCCESS);
}

static void usage(void) {
    printf("Usage: sort [options] [files]\n\n");
    printf("Brief: Sorts the lines of text files.\n\n");
    printf("Options:\n");
    printf("  --help    Display this information and exit\n");
    printf("  --version Display program version and exit\n");
    exit(EXIT_SUCCESS);
}

static void getargs(int argc, char *const argv[]) {
    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];

        if (!strcmp(arg, "--help"))
            usage();
        else if (!strcmp(arg, "--version"))
            version();
        else if (nfiles++ == 0)
            filenames = &argv[i];
    }
}

int main(int argc, char *const argv[]) {
    getargs(argc, argv);

    if (nfiles == 0) {
        sort("/dev/tty");
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < nfiles; i++) {
        const char *filename = filenames[i];
        struct stat st;

        if (!strcmp(filename, "-")) {
            filename = "/dev/tty";
        } else {
            if (stat(filename, &st) == -1) {
                fprintf(stderr, "sort: cannot stat %s\n", filename);
                continue;
            }
            if (S_ISDIR(st.st_mode)) {
                fprintf(stderr, "sort: %s is a directory\n", filename);
                continue;
            }
        }

        sort(filename);
    }

    return EXIT_SUCCESS;
}
