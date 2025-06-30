import React from "react";
import "./App.css";

function Profile({fullName, city, phone, email, experience, skills, photoUrl}){
    return(
        <div className="profile-card">
            <img className="avtar" alt={fullName} src={photoUrl}></img>
            <h2>{fullName}</h2>
            <p><strong>Город:</strong> {city}</p>
            <p><strong>Телефон:</strong> {phone}</p>
            <p><strong>Email:</strong> {email}</p>
            <p><strong>Опыт работы:</strong> {experience}</p>

      <h3>Навыки:</h3>
      <ul>
        {skills.map((skill,index)=>(<li key={{index}}>{skill}</li>))}
      </ul>

        </div>
    );

}
export default Profile;