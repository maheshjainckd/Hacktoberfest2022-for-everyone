import React from "react";
import "./LapNote.css";

const LapNote = (props) => {
  return (
    <div>
      <p className="fancy">
        {"Lap" + props.lapNum + ':  '}
        {props.hours < 10 ? "0" + props.hours : props.hours}
        {":"}
        {props.minutes < 10 ? "0" + props.minutes : props.minutes}
        {":"}
        {props.seconds < 10 ? "0" + props.seconds : props.seconds}
        {':'}
        {props.mini_secs < 10 ? "0" + props.mini_secs : props.mini_secs}
      </p>
    </div>
  );
};

export default LapNote;
