import React from "react";
import "./App.css"


function Moviecard (props){
    const { title, director, year, studio, posterUrl, facts} = props;
    return(
        <div className="movie-card">
            <h2>{title}</h2>
            <p><strong>Режиссёр:</strong> {director}</p>
            <p><strong>Год выпуска:</strong> {year}</p>
            <p><strong>Киностудия:</strong> {studio}</p>
            <img src={posterUrl} alt={title} className="poster"></img>
            <h3>Интересные факты: </h3>
            <ul>
                {facts.map((fact,index)=>(
                    <li key={index}>{fact}</li>
                ))}
            </ul>

        </div>
    );
}
export default Moviecard;