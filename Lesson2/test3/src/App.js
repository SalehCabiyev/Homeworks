import React from "react";
import Clock from "./components/Clock";
import "./App.css";

function App(){
  return(
    <div className="App">
    <h1>Текущее время</h1>
    <Clock></Clock>

    </div>
  );
}
export default App;