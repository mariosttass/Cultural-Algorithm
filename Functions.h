#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define VARS 2 
#define OFFSET 4000
struct atom{
        int geno[VARS];
        double pheno[VARS];
        double fitness;
};


double rnd(void);
atom Mutation (atom x, double prob, int BITS);
atom Crossover (atom p1, atom p2, int BITS);
String Int2Str(int x, int BITS);
int Str2Int(String x, int BITS);
void Geno2Pheno(atom & x, int BITS, int fun);
void Fitness(atom & x, int BITS, int fun);
void HillClimb(atom & x, int BITS, int fun);
void Display(atom * x,int N, int BITS, FILE *f1);
int Roulette(atom * x, int N);
int FindBest(atom *x, int N);
void UpdateBeliefSpace(atom best, atom BeliefSpace[], int B);
int HammDist(int gen1, int gen2);
int FindDistance(atom best,int point, atom BeliefSpace[], int B);
atom Compare(atom best,int position, int BITS, int fun, atom BeliefSpace[]);
void cleanFlagBS();
void algorithm();





