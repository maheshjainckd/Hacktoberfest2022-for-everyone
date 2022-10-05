import React from 'react';
import { Routes, Route } from 'react-router-dom';
import Home from '../pages/Home'
import Detail from '../pages/Detail'
import NotFound from '../pages/NotFound'
import CreateTodo from '../pages/CreateTodo';
import FetchingData from './FetchingData';
const RoutesHome = () => {
    return (
        <div>
            
                <Routes>
                    <Route path='/' element={<Home />}></Route>
                    <Route path='/detail-todo/:id' element={<Detail />}></Route>
                    <Route path='/create-todo/' element={<CreateTodo />}></Route>
                    <Route path='/fetching-data/' element={<FetchingData />}></Route>
                    <Route path='*' element={<NotFound />}></Route>
                </Routes>
            
        </div>
    );
};

export default RoutesHome;