import React from "react";
import "./Pause.css"
import { useSelector, useDispatch } from "react-redux";


const Pause = () => {
  const dispatch = useDispatch();
  const pause = useSelector(state => state.pause)


  const pauseHandler = () => {
    dispatch({ 
      type: "PAUSE"
     })
  }

  return <button onClick={pauseHandler} className="button button4">{!pause ? "Pause" : "Resume"}</button>;
};

export default Pause;
