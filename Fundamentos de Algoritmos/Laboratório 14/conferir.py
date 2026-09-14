"""Laboratório 14 - Módulo com as regras de validação de senha."""


def oito(senha):
    """A senha tem pelo menos 8 caracteres."""
    return len(senha) >= 8


def maiuscula(senha):
    """A senha contém ao menos uma letra maiúscula."""
    return any(c.isupper() for c in senha)


def minuscula(senha):
    """A senha contém ao menos uma letra minúscula."""
    return any(c.islower() for c in senha)


def numero(senha):
    """A senha contém ao menos um dígito."""
    return any(c.isdigit() for c in senha)
