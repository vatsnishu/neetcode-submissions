class MinStack:

    def __init__(self):
        self.stack = []
         

    def push(self, val: int) -> None:
        self.stack.append(val)
        

    def pop(self) -> None:
        self.stack.pop()
      

    def top(self) -> int:
        last_ele=self.stack[-1]
        return last_ele

    def getMin(self) -> int:
        min_ele=self.stack[0]
        i=1
        while i < len(self.stack):
            if self.stack[i]<=min_ele:
                min_ele=self.stack[i]
            i=i+1
        return min_ele            