import Reac from 'react';
import { HiOutlinePencil } from 'react-icons/hi';
import { MdOutlineDeleteForever } from 'react-icons/md';
import { GlobalContext } from '../context';
import { useNavigate} from 'react-router-dom'


const TodoDetailCard = ({ todo }) => {

    const { data, setData, setUpdte } = GlobalContext();
    // const { id } = useParams();
    

    const navigate = useNavigate();

    const deleteHandler = (e) => {
        const todo = data.find(element => element.id === Number(todo.id));
        console.log(todo)
        if (todo) {
            setData(data.filter(element => element.id !== Number(todo.id)))
            navigate('/')
            console.log(data.filter(element => element.id !== Number(todo.id)))
            console.log(data)

        }
    }

    const updateHandler = (e) =>{
        setUpdte(true)
    } 

    return (
        <div className='mt-5 mb-5 d-flex  align-items-center justify-content-center text-center'>
            <div className='col-8 '>
                <div className="card">
                    <div className="card-body">
                        <h3 className=" card-title">{todo.title}</h3>
                        <p className="card-body">{todo.body}</p>
                    </div>
                    <div className="card-footer d-flex justify-content-end">
                        <button className='btn btn-danger mx-2' onClick={deleteHandler}><MdOutlineDeleteForever /></button>
                        <button className='btn btn-info' onClick={updateHandler}><HiOutlinePencil /></button>
                    </div>
                </div>
            </div>
            {/* {todo === true
                ? <div className='col-8'>
                    <div className="card">
                        <div className="card-body">
                            <h3 className=" card-title">{todo.title}</h3>
                            <p className="card-body">{todo.body}</p>
                        </div>
                    </div>
                </div>
                // todo test params if number
                // todo design the result
                : <div>no item find with id {id}</div>} */}
        </div>
    );
};

export default TodoDetailCard;