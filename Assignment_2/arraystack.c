#include "arraystack.h"

// arraylist에서 만든 것들 가져다가 쓰되, 꽉 찬 상태에서 push를 하면 어떻게 할 것인지 논의해야 함
// top element를 트래킹하는 것, 새로운 원소를 push 할때 적절한 위치에 들어가도록 하는 것만 신경써주면 될 듯
ArrayStack* createArrayStack();
int pushLS(ArrayStack* pStack, StackNode element);
StackNode* popLS(ArrayStack* pStack);
StackNode* peekLS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);