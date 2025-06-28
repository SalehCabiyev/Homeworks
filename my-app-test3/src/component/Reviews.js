import React from "react";
import "./App.css"

function Reviews(){
    const reviews = [
    "Очень вдохновляющая книга! Заставляет задуматься о жизни и судьбе.",
    "Простым языком о важных вещах. Одна из моих любимых.",
    "Идеально для тех, кто ищет смысл и направление."
  ];
    return(
        <div className="reviews">
            <h3>Рецензии:</h3>
            <ul>
               {reviews.map((text,index)=>(<li key={index}>{text}</li>))}
            </ul>

        </div>
        
    );
}
export default Reviews;