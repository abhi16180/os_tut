#include <stdio.h>

int findLRU(int pageFrequency[], int n)
{
    int i, minimum = pageFrequency[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (pageFrequency[i] < minimum)
        {
            minimum = pageFrequency[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    int nf, np, frames[10], pages[30], counter = 0, pageFrequency[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &nf);

    printf("Enter number of pages: ");
    scanf("%d", &np);

    printf("Enter reference string: ");

    for (i = 0; i < np; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < nf; ++i)
    {
        frames[i] = -1;
    }

    for (i = 0; i < np; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < nf; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                pageFrequency[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < nf; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    pageFrequency[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            pos = findLRU(pageFrequency, nf);
            counter++;
            faults++;
            frames[pos] = pages[i];
            pageFrequency[pos] = counter;
        }

        printf("\n");

        for (j = 0; j < nf; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);
    printf("\n\nPage Ratio = %f", (float)faults / np);
    printf("\n\nTotal page hits = %d", np - faults);
    printf("\n\nHit Ratio = %f", (float)(np - faults) / np);

    return 0;
}