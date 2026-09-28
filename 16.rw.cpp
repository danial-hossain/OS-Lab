Reader-Writer Problem
Reader’s Part-
int rc = 0;
Binary Semaphore mutex = 1;
Binary Semaphore db = 1;

void Reader(void)
{
    while (true)
    {
        down(mutex);
        rc = rc + 1;
        if (rc == 1) then down(db);   
        up(mutex);

        DB                             

        down(mutex);
        rc = rc - 1;
        if (rc == 0) then up(db);      
        up(mutex);
        Process_data;
    }
}

Writer’s Part-
void Writer(void)
{
    while (true)
    {
        down(db);
        
        DB                     

        up(db);
    }
}

