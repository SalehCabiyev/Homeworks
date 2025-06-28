
import React,{Component} from "react";
import BookInfoClass from "./components/BookInfoClass";
import "./App.css";






class App extends Component {
  render(){
    return(<div className="App">
      <h1>Моя любимая книга</h1>
      <BookInfoClass></BookInfoClass>

    </div>);
  }

}
export default App;