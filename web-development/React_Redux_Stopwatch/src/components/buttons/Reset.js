import React from "react";
import "./Reset.css";
import {  useDispatch } from "react-redux";

const Reset = () => {
  const dispatch = useDispatch();

  const resetHandler = () => {
      dispatch({
        type: "RESET",
      });

  };

  return (
    <button onClick={resetHandler} className="button button3">
      Reset
    </button>
  );
};

export default Reset;
