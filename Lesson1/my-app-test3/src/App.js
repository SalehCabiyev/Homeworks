import React from "react";
import BookInfo from "./component/BookInfo";
import Reviews from "./component/Reviews";
import "./App.css";
function App(){
  return(
    <div className="App">
      <h1>Моя любимая книга</h1>
      <BookInfo></BookInfo>
      <Reviews></Reviews>

    </div>
  );
}
export default App;