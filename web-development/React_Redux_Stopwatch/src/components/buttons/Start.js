import React from "react";
import "./start.css"
import { useDispatch, useSelector } from "react-redux";


const Start = () => {
  const dispatch = useDispatch();
   const start = useSelector(state => state.start)

  const startHandler = () => {
    dispatch({
      type: "START"
    })
  }

  return <button  onClick={startHandler}  className={`${start ? " hiddenProp " : " button button1" }`}>Start</button>;
};

export default Start;

