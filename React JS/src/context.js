import React, { useContext, useEffect, useState } from "react";
import { todos } from './data';
import axios from 'axios';

const AppContext = React.createContext()



export const AppProvider = ({ children }) => {
    const [data, setData] = useState(JSON.parse(localStorage.getItem('todoItem')) || todos);
    const [loading, setLoading] = useState(false);
    const [update, setUpdte] = useState(false);
    

    useEffect(() => {
        localStorage.setItem('todoItem', JSON.stringify(data))
    }, [data]);

    const url = 'http://localhost:5000/api/v1/todo/';

    // const fetchData = async () => {
    //     try {
    //         const { data } = await axios.get(url); 
    //         setData(data.data);
    //     } catch (err) {
    //         console.log(err)
    //     }
    // };

    // const updateData = async (id, body) => { 
    //     try {
    //         const response = await axios.patch(`${url}${id}`, body)
    //             .then(res => res.data);
    //         // console.log('update data',response.data);
    //     }catch(err){console.log(err)}
    // };
    

    // useEffect(() => {
    //     fetchData();
    // }, [])

    // useEffect()

    
    return (
        <AppContext.Provider value={{
            data,
            setData,
            loading,
            update,
            setUpdte,
            // updateData,
        }} >
            {children}
        </AppContext.Provider>
    )
}

export const GlobalContext = () => {
    return useContext(AppContext);
}