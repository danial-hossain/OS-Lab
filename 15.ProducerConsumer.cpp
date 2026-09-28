Semaphore Empty = N;
Semaphore Full = 0;
Semaphore S = 1;


Producer:
while(true)
{
    item = produce_item();

    Down(Empty);
    Down(S);

    Buffer[In] = item;
    In = (In + 1) mod N;

    Up(S);
    Up(Full);
}


Consumer:
while(true)
{
    Down(Full);
    Down(S);

    Item = Buffer[Out];
    Out = (Out + 1) mod N;

    Up(S);
    Up(Empty);

    consume_item(Item);
}