"""
Definition
===============================

 items = [monkey, banana, box]

 positions = [0, 1, 2]

OPERATORS
===============================

Move(subject, x1, x2)
PC: monkeyAt(x1), monkeyLevelDown
A: monkeyAt(x2)
D: monkeyAt(x1)

PushBox(x1,x2)
PC: monkeyAt(x1), boxAt(x1), monkeyLevelDown
A: monkeyAt(x2), boxAt(x2)
D: monkeyAt(x1), boxAt(x1)

ClimbBox(x, direction={Up, Down})
PC: monkeyAt(x), boxAt(x), monkeyLevelDown
A: monkeyLevelUp
E: monkeyLevelDown

HaveBanana(x)
PC: monkeyAt(x), bananaAt(x), boxAt(x), monkeyLevelUp
A: GetBananaAt(x)


INITIAL STATE - Properties
===========================

monkeyAt0, monkeyLevelDown, bananaAt1, boxAt2


GOAL STATE - Properties
===========================

GetBanana(at 1)

"""

import pdb
from random import shuffle

class State:
    def __init__(self):
        self.properties = self.generateStates()

    def __eq__(self, other):
        return self.properties == other.properties

    def generateStates(self):
        """
        Generates all possible properties
        :return: list of all properties
        """
        properties = set()

        POSITIONS = [0, 1, 2]
        ELEMENTS = ["monkey", "banana", "box"]

        for el in ELEMENTS:
            for pos in POSITIONS:
                properties.add(el + "At" + str(pos))

        properties.add('monkeyLevelUp')
        properties.add('monkeyLevelDown')
        properties.add('haveBanana')
        return properties

    def setProperties(self, properties):
        self.properties = properties

    def __str__(self):
        return str(self.properties)
    def __repr__(self):
        return str(self.properties)


class Operation:
    def __init__(self, name):
        self.name = name
        self.PC = set()
        self.A = set()
        self.E = set()

    def __str__(self):
        return "{}".format(self.name)

    def __eq__(self, other):
        return self.name == other.name

    def __hash__(self):
        return hash(self.name)

    def canApply(self, state):
        """
        Return T/F if is possible to apply this operation to this state
        :param state: State to test if this Operation could apply here
        :return: True or False based on Preconditions
        """
        return self.PC.intersection(state.properties) == self.PC

    def apply(self, state):
        """
        Return state after apply this operation
        :param state: original state
        :return: new state after apply this operation
        """
        print("Apply {} to state".format(self.name))
        s = State()
        properties = set()
        if self.canApply(state):
            properties = state.properties.union(self.A)
            properties = properties.difference(self.E)
        else:
            print("Cannot apply {} to state {}".format(self.name, state))
        s.setProperties(properties)
        return s

    def show(self):
        """
        Show actions verbose
        :return:
        """
        print(self.name)
        print("PC: {}".format(self.PC))
        print("A: {}".format(self.A))
        print("E: {}".format(self.E))

class Move(Operation):
    def __init__(self, object, x, y):
        self.name = "Move{}({},{})".format(object, x, y)
        self.object = object
        self.x = x
        self.y = y
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def getPreconditions(self):
        p = set()
        p.add(self.object + "At" + str(self.x))
        if self.object == 'monkey':
            p.add('monkeyLevelDown')
        return p

    def __repr__(self):
        return Operation.__str__(self)

    def getA(self):
        p = set()
        p.add(self.object + "At" + str(self.y))
        return p

    def getE(self):
        p = set()
        p.add(self.object + "At" + str(self.x))
        return p

class PushBox(Operation):
    def __init__(self, x, y):
        self.name = "PushBox({},{})".format(x, y)
        self.x = x
        self.y = y
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def __repr__(self):
        return Operation.__str__(self)

    def getPreconditions(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        p.add("monkeyLevelDown")
        return p

    def getA(self):
        p = set()
        p.add("boxAt" + str(self.y))
        p.add("monkeyAt" + str(self.y))
        return p

    def getE(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        return p

class ClimbBox(Operation):
    def __init__(self, x, updown):
        self.name = "ClimbBox{}(at {})".format(updown, x)
        self.x = x
        self.updown = updown
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def __repr__(self):
        return Operation.__str__(self)

    def getPreconditions(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        if self.updown == 'Up':
            p.add("monkeyLevelDown")
        else:
            p.add("monkeyLevelUpAt{}".format(self.x))
        return p

    def getA(self):
        p = set()
        if self.updown == 'Up':
            p.add("monkeyLevelUpAt{}".format(self.x))
        else:
            p.add("monkeyLevelDown".format(self.x))
            p.add("monkeyAt{}".format(self.x))
        return p

    def getE(self):
        p = set()
        if self.updown == 'Up':
            p.add("monkeyLevelDown")
        else:
            p.add("monkeyLevelUpAt{}".format(self.x))
        return p

class HaveBanana(Operation):
    def __init__(self, x):
        self.name = "GetBanana(at {})".format(x)
        self.x = x
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def __repr__(self):
        return Operation.__str__(self)

    def getPreconditions(self):
        p = set()
        p.add("boxAt" + str(self.x)) # ? could I ommit this state
        p.add("monkeyAt" + str(self.x))
        p.add("bananaAt" + str(self.x))
        p.add("monkeyLevelUpAt{}".format(self.x))
        return p

    def getA(self):
        p = set()
        p.add("haveBanana")
        return p

    def getE(self):
        p = set()
        return p

def generateOperations(initial):
    """
    Generates all possible operations for some state
    :param initial: State
    :return: list of operations
    """
    operations = list()
    s = State()
    properties = s.generateStates()

    elements = ['banana', 'monkey', 'box']
    movement = ['Up', 'Down']
    positions = [0, 1, 2]
    #Generate Move and PushBox Operations
    for x in positions:
        for y in positions:
            if x!=y:
                operations.append(Move('monkey', x, y))
                operations.append(PushBox(x,y))

        #Generate ClimbBox
        for direction in movement:
            operations.append(ClimbBox(x, direction))

    for item in list(initial.properties):
        if 'banana' in item:
            operations.append(HaveBanana(item.split('At')[1]))
    return operations


def selectOperation(cs, gs):
    """
    Select a list of operations for all possible considering the goal state (gs) as
    intersection of operations A's
    :param cs: initial state
    :param gs: goal state
    :return: list of possible operations
    """
    return list(set(filter(lambda x: len(x.A.intersection(gs)) > 0, generateOperations(cs))))

def isFinalState(state, goal):
    """
    Check if a state is final
    :param state: state to check
    :param goal: goal state
    :return: true or false
    """
    return state.properties.intersection(goal.properties) == goal.properties

def STRIPSiter(state, goal):
    """
    Execute STRIPS (iterative) algorithm to find a sequence of operations
    from initial state to goal state
    :param state: initial state
    :param goal: goal state
    :return: plan of operations or False
    """
    plan = []
    stack = list(goal.properties)
    #Using stack to keep it simple
    while len(stack) > 0:
        #First objective of the stack
        target = stack[0]
        #If objective is action - apply and remove objective. New state is the result
        #of apply this operation
        if type(target) in [ClimbBox, HaveBanana, PushBox, Move]:
            state = target.apply(state)
            plan.append(target)
            stack.remove(target)
        #If target is already in properties, just remove it - Sussman anomaly presents
        #here
        elif target in state.properties:
            stack.remove(target)
        #If target == str means is a property.
        elif type(target) == str:
            #Generate a list of operations which could satisfy this property
            operations = list(selectOperation(state, {target}))
            #pdb.set_trace()
            #If there are operations to consider...
            if len(operations) > 0:
                # Heuristic - if target is about monkey position, filter that operations
                # on Move (PushBox operations also have Add Properties about monkey position, so
                # better to prune)
                if 'monkeyAt' in target:
                    operations = list(filter(lambda x: type(x) == Move, operations))

                # Shuffle operations selected - prevent strange loops
                shuffle(operations)
                # Select one of the randomized operations
                operation = operations[0]
                # Push on top
                stack = [operation] + stack
                # And also push on top the preconditions of the operation
                stack = list(operation.PC) + stack
            #If there are no solution, return false
            else:
                #Break the condition to exit
                stack = []
                plan = False
    return plan

# TESTS
# -----------------------------
# m = Move("monkey", 0, 2)
# pb = PushBox(2,1)
# cb = ClimbBox(1, "Up")
# cb2 = ClimbBox(1, "Down")
# hb = HaveBanana(1)

# s1 = m.apply(initial)
# s2 = pb.apply(s1)
# s3 = cb.apply(s2)

# s4 = cb2.apply(s3)
# s5 = cb.apply(s4)
# s6 = hb.apply(s5)
# print(s6)

initial = State()
#Simple state
#initial.setProperties({"monkeyAt0", "bananaAt1", "boxAt1", "monkeyLevelDown"})

#Another state with Monkey up
#initial.setProperties({"monkeyAt2", "bananaAt1", "boxAt2", "monkeyLevelUpAt2"})

#Lab state
initial.setProperties({"monkeyAt0", "bananaAt1", "boxAt2", "monkeyLevelDown"})

goal = State()
goal.setProperties({'haveBanana'})

print("Initial state: \n---------\n{}\n".format(initial))
print("Goal state: \n---------\n{}\n".format(goal))
print("STRIPS START\n==============")
plan = STRIPSiter(initial, goal)
if plan:
    print("\nDone! Final plan: \n{}".format(plan))
else:
    print("STRIPS did not find solution")
