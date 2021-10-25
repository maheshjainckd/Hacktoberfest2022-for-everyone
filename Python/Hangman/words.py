import random


def load_words():
    """
    this function help to load more word by updating word_list (list)    
    Example :-
        word_list = ["learning", "kindness", "joy", "kiet", "good"] (old)
        word_list = ["learning", "kindness", "joy", "kiet", "good" ,"hello"] (new)
    """
    word_list = ["learning", "kindness", "joy", "kiet", "good"]

    # uncomment the below for testing
    
    # WORDLIST_FILENAME = "words.txt"
    # inFile = open(WORDLIST_FILENAME, 'r', 0)
    # line = inFile.readline()
    # word_list = string.split(line)

    return word_list


def choose_word():
    """
    word_list (list): list of words (strings)
    this function return one random world from list
    """
    word_list = load_words()
    secret_word = random.choice(word_list)
    secret_word = secret_word.lower()
    return secret_word
