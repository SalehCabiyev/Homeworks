import React from "react";
import "./CityInfo.css";



function CityInfo(){
    return(
        <div>
            <h2>Информация о городе</h2>
            <ul>
                <li><strong>Страна: </strong> Азербайджан</li>
               
                <li><strong>Население:</strong> более 10 миллионов человек</li>
            </ul>
            <h3>Достопримечательности:</h3>
            <div className="images">
                <img
                    src="https://upload.wikimedia.org/wikipedia/ru/thumb/0/0f/Flame_Towers.JPG/960px-Flame_Towers.JPG?20130203163953"
                     alt="Flame Towers"
                    />
                 <img
                    src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTyPzp5UxRIxURfetWfWeI7_iJxLKTVu-ri2g&s"
                    alt="Icherisheher"
                />
                <img
                    src="https://dynamic-media-cdn.tripadvisor.com/media/photo-o/28/ba/98/8c/baku-boulevard.jpg?w=900&h=500&s=1"
                    alt="Baku Boulevard"
                 />
            </div>

            
        </div>
    );
}
export default CityInfo;
