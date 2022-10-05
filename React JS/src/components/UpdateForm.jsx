import React,{useEffect, useState} from 'react';
// import { useParams } from 'react-router-dom';
import { GlobalContext } from '../context';

const UpdateForm = ({todo}) => {

    const [title, setTitle] = useState(todo.title);
    const [body, setBody] = useState(todo.body);
    const [check, setChek] = useState(todo.done);
    const { data, setData, setUpdte, updateData } = GlobalContext();
    const titleHandler = (e) => {
        setTitle(e.target.value);
    }

    const bodyHandler = (e) => {
        setBody(e.target.value);
    }

    const checkHandler = (e) => {
        setChek(e.target.checked)
    }

    const fin = () => {
        if (check) {
            return new Date().toString()
        }
        return ""
    }

    const url = 'http://localhost:500/api/v1/todo/'
    const formHandler = (e) => {
        e.preventDefault();
        todo.body = body;
        todo.title = title;
        todo.updated = new Date().toString();
        todo.done = check;
        todo.ended = fin();
        // console.log('todo', todo)
        updateData(todo._id, todo);
        
        // let newData = data.filter(ele => ele.id !== Number(todo.id))
        
        // newData = [...newData, todo]
        
        // newData.sort(function (a,b){return a.id- b.id})
        // setData(newData);
        setUpdte(false);
    };

    
        

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
                                rows='10'
                                style={{height: '200px'}}
                                className=" form-control" id="body" placeholder="create details ... !" name='body' />
                            <label htmlFor="floatingInput">Details</label>
                        </div>

                        <div className="mb-3 form-check">
                            <input type="checkbox" name="done" id="done"
                            defaultChecked={check}
                            onChange = {checkHandler}    
                            className='form-check-input' />
                            <label htmlFor="done" className='form-check-label'>done</label>
                        </div>
                        <button type="submit" className='btn btn-primary'>Create</button>
                    </form>
                </div>
            </div>
        </div>
    );
};

export default UpdateForm;





// const formHandler = (e) => {
    // old function
//     e.preventDefault()
//     // get new data
//     // stock in variable
//     const item = {
//         id: todo.id,
//         title,
//         body,
//         created: todo.created,
//         updated: new Date().toString(),
//         done: check,
//         ended: fin()
//     }
//     todo.body = body
//     todo.title = title
//     todo.updated = new Date().toString()
//     todo.done = check
//     todo.ended = fin()
//     // const {id} = useParams()
//     // filter and delete old value
//     let newData = data.filter(ele => ele.id !== Number(todo.id))
//     // add new value to data
//     newData = [...newData, todo]
//     // filter data
//     newData.sort(function (a,b){return a.id- b.id})
//     setData(newData);
//     setUpdte(false);
// };