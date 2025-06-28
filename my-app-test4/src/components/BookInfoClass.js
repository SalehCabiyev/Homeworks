import React, { Component } from "react";
import "./App.css";

class BookInfoClass extends Component {
    render(){
        return(
            <div className="book-card">
                <h2>1984</h2>
                <p><strong>Автор:</strong> Джордж Оруэлл</p>
                <p><strong>Жанр:</strong> Антиутопия, политическая фантастика</p>
                <p><strong>Количество страниц:</strong> 328</p>

                <h3>Рецензии:</h3>
             <ul>
                <li>«Шедевр, который никогда не потеряет актуальности.»</li>
                <li>«Мощная и тревожная книга о контроле и свободе.»</li>
                <li>«Заставляет задуматься о будущем человечества.»</li>
             </ul>

            </div>
        );
    }


}
export default BookInfoClass;