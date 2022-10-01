import React from "react";
import "./Lap.css"
import { useSelector, useDispatch } from "react-redux";



const Lap = () => {
  const dispatch = useDispatch();

  const minutes = useSelector((state) => state.minutes);
  const seconds = useSelector((state) => state.seconds);
  const hours = useSelector((state) => state.hours);
  const lap = useSelector((state) => state.lap);
  const mini_secs = useSelector((state) => state.mini_secs);

  const laps = {
    key : lap.length,
    lapNum: lap.length+1,
    mini_secs,
    seconds ,
    minutes,
    hours
  }


  const lapHandler = () => {
    dispatch({ 
      type: "LAP",
      laps:laps
     })
  }

  return <button onClick={lapHandler}  className="button button2">Lap</button>;
};

export default Lap;

