import React from "react";
import Petcard from "./components/Petcard";
import "./App.css"

function App(){
  const MyPet={
    name: "Tom",
    species: "Кошка",
    age: 3,
    breed: "Шотландская вислоухая",
    imageUrl: "https://images.all-free-download.com/images/graphicwebp/cat_hangover_relax_213869.webp", 
    facts: [
      "Любит спать на клавиатуре",
      "Обожает тунца",
      "Боится пылесоса"
    ]

  };
  return(
    <div className="App">
        <h1>Мой домашний питомец</h1>
        <Petcard {...MyPet}></Petcard>
    </div>
  );
}
export default App;