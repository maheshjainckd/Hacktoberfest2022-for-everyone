import React from 'react';
import { useState } from 'react';
import { Link } from 'react-router-dom';
import { GlobalContext } from '../context';
// import {useParams} from 'react-router-dom'
// // import TodoDetailCard from '../components/TodoDetailCard';
// import { GlobalContext } from '../context';

const TodoForm = () => {
    const [title, setTitle] = useState('');
    const [body, setBody] = useState('');
    const [check, setChek] = useState(false);
    const {data, setData} = GlobalContext()

    const titleHandler = (e) => {
        setTitle(e.target.value);
    }

    const bodyHandler = (e) => {
        setBody(e.target.value);
    }

    const checkHandler = (e) => {
        setChek(e.target.checked)
    }

    function getRandom(max) {
        return Math.floor(Math.random() * max)
    }

    const formHandler = (e) => {
        e.preventDefault();
        
        const todo = {
            id: getRandom(1000),
            title,
            body,
            created: new Date().toString(),
            updated: new Date().toString(),
            done:check,
            ended: new Date().toString(),
        }
        setData([...data, todo])
        console.log(data, [...data, todo])
    }  
    return (
        <div className='mt-5 mb-5 d-flex align-items-center justify-content-center'>
            <div className="col-8 ">
                <div className="card">
                    <form action="" className='p-5' onSubmit={formHandler}>
            
                        <div className="form-floating mb-3">
                            <input type="text"
                                onChange={titleHandler}
                                value={title}
                                className="form-control" id="title"
                                required
                                placeholder="get milk 🥛" name='title' />
                            <label htmlFor="floatingInput">Title</label>
                        </div>

                        <div className="form-floating mb-3">
                            <textarea type="text"
                                onChange={bodyHandler}
                                value={body}
                                required
                                className="form-control" id="body" placeholder="create details ... !" name='body' />
                            <label htmlFor="floatingInput">Details</label>
                        </div>

                        <div className="mb-3 form-check">
                            <input type="checkbox" name="done" id="done"
                            defaultChecked={check}
                            onChange = {checkHandler}    
                            className='form-check-input' />
                            <label htmlFor="done" className='form-check-label'>done</label>
                        </div>
                        <Link to="/"><button type="submit" className='btn btn-primary'>Create</button></Link>
                    </form>
                </div>
            </div>
        </div>
    );
};

export default TodoForm;