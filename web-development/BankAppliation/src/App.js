import React, { useState } from 'react'
import { BrowserRouter as Router, Route, Switch, } from 'react-router-dom';
import "./styles/App.css"
import Navbar from './components/widgets/Navbar'
import Home from './components/pages/Home'
import Users from './components/pages/Users'
import History from './components/pages/History'
import Register from './components/pages/Register';
import Demo from './components/pages/Demo';
import Deposite from './components/pages/Deposite';
import Login from './components/pages/Login';
import Error from './components/pages/Error';
function App() {

  const [authorize, setauthorize] = useState(true) // change it to false to enable authentication 
                                                  // username :- earthboxer 
                                                  // password :- earthboxer
                                                  


  return (
    <Router>
      <div className="App">
        <Navbar />
        <Switch>
          <Route path="/home/users/:transfer" exact component={() => <Demo authorize={authorize} />} />
          <Route path="/home/users" exact component={() => <Users authorize={authorize} />} />
          <Route path="/home/depositeandwithdraw" exact component={() => <Deposite authorize={authorize} />} />
          <Route path="/home/history" exact component={() => <History authorize={authorize} />} />
          <Route path="/home/register" exact component={() => <Register authorize={authorize} />} />
          <Route path="/home" exact component={() => <Home authorize={authorize} setauthorize={setauthorize} />} />
          <Route path="/" exact component={() => <Login authorize={authorize} setauthorize={setauthorize} />} />
          <Route component={Error} />
        </Switch>

      </div>
    </Router>
  )
}

export default App


