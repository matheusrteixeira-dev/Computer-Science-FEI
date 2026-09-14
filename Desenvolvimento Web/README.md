# Desenvolvimento Web (Web Development)

Front-end labs with HTML, CSS and JavaScript, followed by Node.js back ends with Express, EJS and MongoDB. The problem statements with screenshots are in [images](images).

## Front end

| Lab | Description |
| --- | --- |
| [Lab01](Lab01/src) | Personal page using basic HTML elements (built on the HTML5 Boilerplate template). |
| [Lab02](Lab02) | Grade table with CSS styling and icons. |
| [Lab03](Lab03/src) | Two-page site about *The Lord of the Rings*: page structure, links and images. |
| [Lab04](Lab04) | Multi-page website for a fictional car dealership (*AutoCar*): shared menu, catalog, contact form, embedded video and map. |
| [Lab05](Lab05/src) | DOM manipulation with JavaScript. |
| [Lab06](Lab06) | Drawing on the Canvas 2D API ([statement](images/lab05.png)). |
| [Lab07](Lab07) | Student registration with final-grade calculation, updating the table through the DOM ([statement](images/lab06.png)). |

## Back end (Node.js)

| Lab | Description |
| --- | --- |
| [Lab08](Lab08) | Express server that serves static HTML pages ([statement](images/lab08.png)). |
| [Lab09](Lab09) | In-memory user registration and listing with Express and EJS ([statement](images/lab09.png)). |
| [Lab10](Lab10) | User sign-up, login and listing persisted in MongoDB with Mongoose. |
| [Lab11](Lab11) | Same application as Lab10 (resubmitted for the following lab). |
| [Lab12](Lab12) | Library: register, search and delete books by author with MongoDB ([statement](images/lab10.png)). |
| [Lab13](Lab13) | Same application as Lab12 (resubmitted for the following lab). |
| [Projeto_Lab_Final](Projeto_Lab_Final) | Final lab project: library system with user sign-up/login and book registration. |
| [Prova](Prova) | Exam: registration and listing of elderly people with MongoDB. |

> These projects are teaching exercises: passwords are stored in plain text, and there is no input validation or authentication middleware.

## Running

The back-end labs need Node.js and a local MongoDB server (`mongodb://localhost`).

```bash
cd Lab12
npm install
npm start        # or: node servidor.js — then open http://localhost:8080
```

Lab01, Lab03 and Lab05 use the HTML5 Boilerplate build (`gulp`); `src/index.html` can also be opened directly in a browser.
