import React from "react";
import ReactDOM from "react-dom";


class Board extends React.Component {
	render()
	{
		for (let x = 0; x < 9
	}
}

class Welcome extends React.Component {
    render()
    {
        return <h1>Hello, {this.props.name}</h1>;

    }
}


ReactDOM.render(
   <Welcome name="juno"></Welcome>,
    document.getElementById("root")
);
