import './App.css';

// import {
//   BrowserRouter,
//   Routes,
//   Route,
// } from "react-router-dom";

import Navbar from './components/navbar/Navbar.js';
import Home from './components/home/Home';
import Bio from './components/bio/Bio';
import About from './components/about/About';
import MyProjects from './components/projects/MyProjects';

// import { BrowserRouter, Routes, Route } from 'react-router-dom';
function App() {
  return (
    <>
    <Navbar />
    <Home />
    <Bio />
    <About />
    <MyProjects />
    </>
  );
}

export default App;
