import React ,{Component} from "react";
import CityInfoClass from "./components/CityInfoClass";
import "./App.css"



class App extends Component {
  render(){
    return(
      <div className="App">
        <h1>Информация о городе</h1>
       <CityInfoClass></CityInfoClass>

      </div>

    );
  }
}
export default App