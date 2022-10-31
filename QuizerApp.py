# QUIZ APP

from question_model import Question
from data import question_data
from quiz_brain import QuizBrain
from ui import QuizInterface

# assign empty list for question
question_bank = []
for question in question_data:
    question_text = question["question"]
    question_answer = question["correct_answer"]
    new_question = Question(question_text, question_answer)
    question_bank.append(new_question)

# getting question
quiz = QuizBrain(question_bank)

# initilize the UI
quiz_ui = QuizInterface(quiz)

# is quiz running
while quiz.still_has_question():
    quiz.next_question()

print("You've completed the quiz")
print(f"Your final score was: {quiz.score}/{quiz.question_number}")
