import React from "react";
import "./Petcard.css"

function Petcard({name, species, age, breed, imageUrl, facts}){
    return(
        <div className="pet-card">
            <img className="pet-photo" alt={name} src={imageUrl}></img>
            <h2>{name}</h2>
            <p><strong>Вид:</strong> {species}</p>
            <p><strong>Порода:</strong> {breed}</p>
            <p><strong>Возраст:</strong> {age} лет</p>
           

      <h3>Факты:</h3>
             <ul>{facts.map((fact,index)=>(<li key={index}>{fact}</li>))}</ul>

        </div>

    );
}
export default Petcard;