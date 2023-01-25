import React from "react";
import ReactDOM from "react-dom";

// class Welcome extends React.Component {
//     render()
//     {
//         return <h1>Hello, {this.props.name}</h1>;

//     }
// }

function Welcome(props) {
    return <h1>Hello, {props.name}</h1>;
}

class Game extends React.Component{
    render(
	 Welcome(props);
	)
}

ReactDOM.render(
    <Game name="juno"></Game>,
//    <Welcome name="juno"></Welcome>,
    document.getElementById("root")
);
