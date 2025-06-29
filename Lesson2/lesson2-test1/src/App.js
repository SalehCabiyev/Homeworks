import React from "react";
import "./App.css"
import Moviecard from "./conponents/Moviecard";

function App(){
  const movieData = {
    title: "Интерстеллар",
    director: "Кристофер Нолан",
    year: 2014,
    studio: "Paramount Pictures, Warner Bros.",
    posterUrl: "https://upload.wikimedia.org/wikipedia/ru/c/c3/Interstellar_2014.jpg?20190423055512",
    facts: [
      "Фильм основан на научных теориях физика Кипа Торна.",
      "Оскар за лучшие визуальные эффекты.",
      "Композитор — Ханс Циммер.",
    ],
  };
  return(
    <div className="App">
      <h1>Мой любимый фильм</h1>
      <Moviecard {...movieData}></Moviecard>

    </div>
  );
}
export default App;