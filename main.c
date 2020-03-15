#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int ns[] = { 10, 100, 1000, 10000 };

void fill_increasing(int *t, unsigned int n) {
    for(int i = 0; i < n; i++)
    {
      t[i] = i + 1;
    }
}

void fill_decreasing(int *t, unsigned int n) {
  for(int i = 0; i < n; i++)
  {
    t[i] = -i;
  }
}

void fill_vshape(int *t, unsigned int n) {
	int *begin; // tworzymy wskaźnik mający przechować pierwszą wartość liczbową tablicy,
	int *end; // tworzymy wskaźnik mający przechować ostatnią wartość liczbową tablicy
	begin = t; // przypisujemy wskaźnikowi miejsce tablicy t[0]
        end = t + n - 1; // przypisujemy wskaźnikowi miejsce ostatnie tablicy (n-1) <- ponieważ jeśli mamy tablice np 100 el. to ostatni element jest na miejscu 99
        int k = n; // zapamiętujemy rozmiar tablicy,
        while (end - begin > 1) // 
            {
                *begin = k; //do miejsca t[0] przypisywana jest wartość k = n np = 100;
                k--; //dekrementacja k; (99)
                *end = k; // do miejsca t[n-1] przypisywana jest wartość k mniejsza o 1 np jesli k = n = 100, to teraz jest to 99,   
                k--; // dekrementacja k np 98
                begin++; //begin teraz będzie wskazywało na t[1] msc tablicy;
                end--; // end teraz wskazuje na t[n-2] msc tablicy;
            }
}

void selection_sort(int *t, unsigned int n) {
    int el_min;
    int el_drugi;
    for(int i = 0; i < n - 1; i++)
    {
     el_min = i;

     for(int d = i + 1; d < n; d++)
     {
         el_drugi = d;
         if(t[el_drugi] < t[el_min])
         {
           int temp = t[el_min];
           t[el_min] = t[el_drugi];
           t[el_drugi] = temp;
         }
     }
    }
}

void insertion_sort(int *t, unsigned int n) {
  int el; // zmienna do pobierania elementu
  int el_dwa; // zmienna do pobrania drugiego elementu do porownania
  for(int i = 1; i < n; i++)
  {
    el = t[i]; //zapamietuje wartosc, ktora jest pod t[i]
    el_dwa = i; // zapamietuje indeks i
    while(el_dwa > 0 && t[el_dwa - 1] > el) //element porownywany nie może być mniejszy niż zero i ma być większy od elementu pierwszego
  {
    t[el_dwa] = t[el_dwa - 1]; // nadpisujemy wartosc, ktora była  pod indeksem i wartoscia mniejsza po lewej stronie (i-1) dzieki czemu teraz pod t[i] jest wartosc wieksza niz pod t[i-1]
    el_dwa--; //zmniejszamy indeks o 1 (tak jakbysmy teraz patrzyli w lewo w tablice)
  }
  t[el_dwa] = el; //przypisujemy zapisana wartosc do miejsca o 1 wcześniej w tablicy,
  }

}

void swap(int *t, int i, int j)
    {
    int temp = t[i];
    t[i] = t[j];
    t[j] = temp;
    }
int choosePivot(int *t, int left, int right) //wybieranie pivota ze środka tablicy
{
    int middle = left + (right - left) / 2; // operacja do wybrania miejsca środkowego pivota,
    int pivotValue = t[middle]; // pivot przyjmuje wartość równą integerowi środkowemu
    swap(t, right, middle); // zamiana miejsc ostatniego ze środkowym, ostatni element do staje wartość środkowego, środkowy natomiast ostatniego,
    return pivotValue; // zwraca wartość piwota
}
int partycjonowanie(int *t, int left, int right)
{
  int pivot_val = choosePivot(t, left, right); // pivot przyjmuje wartość ostatniego elementu
  int granica = left - 1; // wyznaczenie granicy, mniejsze el na lewo większe na prawo od granicy,granica stoi przed pierwszym indeksem
  int i = left; // nasz indeks

  while( i < right)   //dopóki nie dojdziemy do konca tablicy
  {
    if( t[i] < pivot_val) // sprawdzamy czy el pod dana iteracją jest mniejszy od piwota, jesli tak no to zamiana
    {
      granica++;    // najpierw zamiana z el pierwszym po prawej a dopiero potem zamiana granicy, ale żeby nie zamienić elementu samego ze sobą  zwiększamy wcześniej granice
      if(granica != i) //jeśli granica będzie różna od obecnej iteracji wykonujemy zamianę elementów,
      {
        swap(t, granica, i);
      }
    }
    i++;
  }           // zapewniamy aby pivot był w odpowiadającej mu pozycji,
  granica ++; //miejsce podziału tablicy
  if( granica != right)
  {
    swap(t, granica, right);
  }
  return granica; //indeks naszego podziału,
}

int QuickSort(int *t, int left, int right)  //partycjonowanie tablicy
{
  if(left < right)
  {
  int granica = partycjonowanie(t, left, right);
  QuickSort(t, left, granica - 1);
  QuickSort(t, granica + 1, right);
}
}


void quick_sort(int *t, unsigned int n)
{
  QuickSort(t, 0, n - 1); // t to tablica, 0 to początek czyli left, n-1 to koniec tablicy czyli right,
}

 void heapify(int *t, int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && t[l] > t[largest])
            largest = l;

        if (r < n&&t[r] > t[largest])
            largest=r;

        if (largest!= i)
        {
            int temp = t[i];
            t[i] = t[largest];
            t[largest] = temp;

            heapify(t,n , largest);
        }
    }

    void heap_sort(int *t, unsigned int n) {
          for (int i = n /2 - 1; i >= 0; i--)
            heapify(t, n,i);

        for (int i=n-1; i>=0; i--)
        {
            int temp = t[0];
            t[0] =t[i];
            t[i]= temp;

            heapify(t, i, 0);
        }
    }
void fill_random(int *t, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        t[i] = rand();
    }
}

void is_random(int *t, unsigned int n) {
    return;
}

void is_increasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] > t[i - 1]);
    }
}

void is_decreasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] < t[i - 1]);
    }
}

void is_vshape(int *t, unsigned int n) {
    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        assert(*begin > *end);
        begin++;
        assert(*end > *begin);
        end--;
    }
}

void is_sorted(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] >= t[i - 1]);
    }
}

void (*fill_functions[])(int *, unsigned int) = { fill_random, fill_increasing, fill_decreasing, fill_vshape };
void (*check_functions[])(int *, unsigned int) = { is_random, is_increasing, is_decreasing, is_vshape };
void (*sort_functions[])(int *, unsigned int) = { selection_sort, insertion_sort, quick_sort, heap_sort };

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "InsertionSort", "QuickSort", "HeapSort" };

int main() {
    for (unsigned int i = 0; i < sizeof(sort_functions) / sizeof(*sort_functions); i++) {
        void (*sort)(int *, unsigned int) = sort_functions[i];

        for (unsigned int j = 0; j < sizeof(fill_functions) / sizeof(*fill_functions); j++) {
            void (*fill)(int *, unsigned int) = fill_functions[j];
            void (*check)(int *, unsigned int) = check_functions[j];

            for (unsigned int k = 0; k < sizeof(ns) / sizeof(*ns); k++) {
                unsigned int n = ns[k];
                int *t = malloc(n * sizeof(*t));

                fill(t, n);
                check(t, n);

                clock_t begin = clock();
                sort(t, n);
                clock_t end = clock();
                is_sorted(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    return 0;
}
