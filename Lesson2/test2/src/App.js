import React from "react";
import Profile from "./components/Profile";
import "./App.css";


function App(){
  const profileData = {
    fullName: "Mikle Smith",
    city: "Баку",
    phone: "+994 50 123 45 67",
    email: "mike@example.com",
    experience: "2 года разработки на C#, Python и C++",
    skills: ["React", "C#", "Python", "Git", "REST API"],
    photoUrl: "https://i.pravatar.cc/150?img=3" 
  };

  return(<div className="App">
    <h1>Персональная страница</h1>
    <Profile {...profileData}></Profile>
  </div>);
}
export default App;