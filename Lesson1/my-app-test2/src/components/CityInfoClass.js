import React,{Component} from "react";
import "./CityInfoClass.css"
class CityInfoClass extends Component{
    render(){
        return(
            <div className="city-card">
                <h2>Баку, Азербайджан</h2>
                <h3>Достопримечательности:</h3>
                <div className="images">
                    <img src="https://as1.ftcdn.net/jpg/05/01/72/42/1000_F_501724250_gZdCYkwh2JqWTfaNjkvXkhQVDpG313kf.jpg" alt="Flame Towers"></img>
                    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/%D0%91%D0%B0%D0%BA%D1%83%2C_%D0%98%D1%87%D0%B5%D1%80%D0%B8-%D1%88%D0%B5%D1%85%D0%B5%D1%80%2C_%D0%B2%D0%BD%D1%83%D1%82%D1%80%D0%B8.jpg/960px-%D0%91%D0%B0%D0%BA%D1%83%2C_%D0%98%D1%87%D0%B5%D1%80%D0%B8-%D1%88%D0%B5%D1%85%D0%B5%D1%80%2C_%D0%B2%D0%BD%D1%83%D1%82%D1%80%D0%B8.jpg" alt="Icherisheher"></img>
                    <img src="https://www.exploreazerbaijan.com/medias/things_to_do/medium/4/img-7303-1.jpg" alt="Baku Boulevard"></img>
                </div>
                

            </div>
        )
    }
}
export default CityInfoClass;