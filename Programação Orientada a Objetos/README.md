# Programação Orientada a Objetos (Object-Oriented Programming)

Java exercises covering classes, relationships between objects, inheritance, polymorphism, exceptions, generics, design patterns and Swing interfaces in MVC. Several statements are UML diagrams or screenshots, kept in [images](images).

| Class | Exercises | Topics |
| --- | --- | --- |
| [Aula 01](Aula%2001%20Pr%C3%A1tica) | `Ex1`–`Ex9`, `Main` (menu) | Java basics: input with `Scanner`, conditionals and loops (pinball path ([statement](images/lab01_06.png)), salary adjustment ([statement](images/lab01_07.png)), histogram, Pythagorean triples). |
| [Aula 02](Aula%2002%20Pr%C3%A1tica) | `javaapplication1`–`7` | First classes with encapsulation: person, value swapper, rectangle, television, date, employee and invoice. |
| [Aula 03](Aula%2003%20Pr%C3%A1tica) | `Exemplo`, `Exercicio01`–`05` | Constructor overloading, date formats with leap-year handling, heart-rate calculator, rational and complex numbers; aggregation and composition ([statement](images/lab03_06.png), [statement](images/lab03_07.png)). |
| [Aula 04](Aula%2004%20Pr%C3%A1tica) | `Ex01`–`Ex07`, `Exercicio03UML` | Arrays of objects and `ArrayList`, in-memory phone book, chessboard pieces, bank accounts, a car composed of its parts, a UML association. |
| [Aula 05](Aula%2005%20Pr%C3%A1tica) | `JavaApplication1`, `Ex02`–`Ex05` | Inheritance: student/person ([statement](images/lab05_01.png)), quadrilaterals ([statement](images/lab05_02.png)), politicians ([statement](images/lab05_03.png)), ships ([statement](images/lab05_04.png)), bank accounts. |
| [Aula 06](Aula%2006%20Pr%C3%A1tica) | `Ex01`–`Ex05` | Overloading, abstract classes and polymorphism ([statement](images/lab06_02.png)), interfaces (`MovablePoint`/`MovableCircle`, [statement](images/lab06_04.png)), multiple interfaces ([statement](images/lab06_05.png)). |
| [Aula 07](Aula%2007%20Pr%C3%A1tica) | `Ex01`–`Ex04` | Custom exceptions (CPF validation), file-backed phone book with `java.nio`, Factory + Singleton, generic `Pair<F, S>`. |
| [Aula 08](Aula%2008%20Pr%C3%A1tica) | `Exercicio 01`, `Exercicio 02` | Swing calculators organized as Model–View–Control. |
| [Aula 09](Aula%2009%20Pr%C3%A1tica) | `Ex01`, `Ex02` | Swing apps: user registration and search in a text file ([statement](images/lab09_01.png)); veterinary clinic with tabbed panes ([statements](images/lab09_02.png), [class diagram](images/lab09_06.png)). |

Folders named **Exemplos do Professor** contain the instructor's in-class examples, kept unchanged as reference for the exercises.

## Building

The Aula 05 and 09 folders are NetBeans (Ant) projects and can be opened directly in NetBeans. The other exercises compile with `javac`, for example:

```bash
javac -encoding UTF-8 -d out "Aula 01 Prática"/*.java
java -cp out POO.Main
```
