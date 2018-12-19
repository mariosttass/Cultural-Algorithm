//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <sstream>
#include <iomanip>
#include "Basic.h"
#include "View.h"
#include "VisualFunctions.h"
#define VARS 2    

static flagBS;

/* Δήλωση της δόμης δεδόμενων του ατόμου
με χαρακτηριστικά τον γονότυπο,
τον φενότυπο και την ποιότητα του. */
struct atom{
        int geno[VARS];
        double pheno[VARS];
        double fitness;
};

/*Δήλωση της συνάρτης rnd() η οποία όταν καλείται μας επιστρέφει
έναν τυχαίο αριθμό απο 0 εώς 1. */
double rnd(void)
{
        return (double)rand()/(RAND_MAX+0.1);   //!!

}

/*Δήλωση της συνάρτης Mutation, η οποία ειναι υπεύθυνη για την 
μετάλλη του ατόμου. Δέχεται το άτομο, την πιθανοτητα της μετάλλαξης,
και τα ΒΙΤS που έχουμε θέσει. Μας επιστρέφει το μεταλλαγμένο άτομο */
atom Mutation (atom x, double prob, int BITS)
{
        //ginetai praksi xor gia tin antistrofi tou bit
        double E,dek;
        int ak,mp,i,point,mask,Chrom,Chrompos;
        E=VARS*BITS*prob;           // E=ektimisi shmeiwn metallaksis
        ak=(int)E;
        dek=E-ak;
        mp=ak;
        if(rnd()<dek) mp++;
        //printf("BITS=%i prob=%lf E=%lf ak=%i dek=%lf mp=%i\n",BITS,prob,E,ak,dek,mp);
        for(i=0;i<mp;i++)
        {
                point=random(BITS*VARS); // 0 eos 39
                //printf("Before =%s\n",x.c_str());
                //printf("point=%i\n",point);
                Chrom = point/BITS; // 0,1,2,3...
                Chrompos = point%BITS;
                mask = 1<<(BITS-Chrompos-1) ;
                x.geno[Chrom]=x.geno[Chrom]^mask;
               //printf("After =%s\n",x.c_str());
        }
        //getch();
        return x;
}

/*Δήλωση της συνάρτης Crossover, η οποία ειναι υπεύθυνη για την 
για τον ανασυνδυασμό των γονέων για την παραγώγη του απογόνου. 
Δέχεται τους γονείς και τα ΒΙΤS που έχουμε θέσει. Μας επιστρέφει τον απόγονο 
*/
atom Crossover (atom p1, atom p2, int BITS)
{
        //and &
        //or  |
        //xor ^
        //not ~

        int point, mask2, Chrom, Chrompos, j;
        atom child;
        point = random(VARS * BITS-1); //τυχαιός αριθμός απο 0 εώς BITS*VARS
        Chrom = point/BITS; // ο τυχαίος αριθμός διά των αριθμό των BITS
        Chrompos = point%BITS;  //από την θέση 0 έώς 7 το χρωμόσωμα όπου θα γίνει το crossover
        for(j=0;j<Chrom;j++) {
                child.geno[j]=p1.geno[j];
        }
        for(j=Chrom+1;j<VARS;j++)
        {
                child.geno[j]=p2.geno[j];
        }
        mask2 = (1<<BITS-Chrompos-1)-1;
		
		//ορισμός του χρωμοσώματος όπου θα γίνει το crossover
		child.geno[Chrom] = (p1.geno[Chrom]&(~mask2))|(p2.geno[Chrom]& mask2);
        /* θα πάρουμε απο το p1 τόσο όσο ορίζει η mask1
        και απο το p2 τόσο όσο ορίζει η mask2 */
        //enonoume me tin praksi or
        // ~ NOT operator

        /*Αρχικά βρίσκει έναν τυχαίο αριθμό point μεταξύ 0 και BITS*VARS
        αποθηκεύει το αποτέλεσμα της διαίρεσης point/BITS στην μεταβλητή chrom
        άρα το αποτέλεσμα της διαίρεσης θα ειναι 0 ή 1
		αποθηκεύει το υπόλοιπο της διαίρεσης στην μεταβλητή chrompos
		αν το αποτέλεσμα ειναι 0 εκετελείται η δεύτερη for
		όπου ο γονότυπος του παιδιού γίνεται ίσος με τον γονότυπο του δεύτερου γονέα.
        αν το αποτέσμα ειναι 1 εκτελείται η πρώτη for
        όπου ο γονότυπος του παιδιού γίνεται ίσος με τον γονότυπο του δεύτερου γονέα.
		στην συνέχεια βρίσκουμε την μάσκα για να δημιουργήσουμε το γενότυπο που
		δεν αντιγράψαμε απο κάποιον γονέα. */


        return child;
}

/* Η συνάρτηση Int2Str δέχεται εναν ακέραιο αριθμο
και των αριθμο των BITS και μας επιστρέφει μια συμβολοσειρά απο 0 και 1.
Συνεπώς μετατρέπει τους ακέραιους σε συμβολοσειρά απο 0 και 1 
*/
String Int2Str(int x, int BITS)
{
        String s="";
        int mask,i;
        mask= 1<<(BITS-1);
        for(i=0;i<BITS;i++)
        {
                if(x&mask) s+='1'; 
        else
                           s+='0';
        mask=mask>>1;
        }
        return s;
}


/* Η συνάρτηση Str2Int δέχεται μια σ απο 0 και 1
και των αριθμο των BITS και μας επιστρέφει έναν ακέραιο.
Συνεπώς μετατρέπει την συμβολοσειρά 0 και 1 σε ακεραιο αριθμό 
*/
int Str2Int(String x, int BITS)
{
        int i,sum=0,p;


        p=1<<(BITS-1); //128
        for(i=1;i<=BITS;i++)
          {
             if(x[i] =='1')
             sum+=p;
             p=p/2; // p=p>>1;
          }
        return sum;

}

/* Η συνάρτηση Geno2Pheno δέχεται ένα δείκτη ατόμου,
τον αριθμο των BITS και την συνάρτηση για την οποια εκετελείται.
Δεν επιστρέφει τίποτα. Αυτό που κάνει ειναι να μετατρέπει τον γονότυπο του ατόμου
σε φενότυπο.*/
void Geno2Pheno(atom & x, int BITS, int fun)
{
        int j;
        double vhma;
        //vhma=2*M_PI/(pow(2,BITS)-1);

        for(j=0;j<VARS;j++) {
                if(fun==0)
                {
                        vhma=4.096/(pow(2,BITS)-1);
                        x.pheno[j]=x.geno[j]*vhma-2.048;  //Για την συνάρτηση Rosenbrock
                }
                else if(fun==1)
                {
                        vhma =10.24/(pow(2,BITS)-1);
                        x.pheno[j]=x.geno[j]*vhma-5.12; //Για την συνάρτηση Rastrigin
                }
                else if(fun==2)
                {
                        vhma=1000/(pow(2,BITS)-1);
                        x.pheno[j]=x.geno[j]*vhma-500;  //Για την συνάρτηση Schwefel
                }
                else if(fun==3)
                {
                        vhma=100/(pow(2,BITS)-1);
                        x.pheno[j]=x.geno[j]*vhma+0.1; //Για την συνάρτηση του Παραλληλογράμμου
                }
        }
}

/* Η συνάρτηση Fitness δέχεται ένα δείκτη ατόμου,
τον αριθμο των BITS και την συνάρτηση για την οποια εκετελείται.
Δεν επιστρέφει τίποτα. Αυτό που κάνει η συνάρτηση ποιότητας ειναι 
να δημιουργεί την ποιότητα του ατόμου η οποία μας 
χρειάζεται για την αξιολογησή του.
*/
void Fitness(atom & x, int BITS, int fun)
{
        double x1,x2;
        Geno2Pheno(x, BITS, fun);
        x1=x.pheno[0];
        x2=x.pheno[1];
        if(fun==0)
                x.fitness= (100*pow(x1*x1-x2,2)+pow(1-x1,2));   //rosenbrock
        else if(fun==1)
                x.fitness= 20 + (pow(x1,2) - 10*cos(2*M_PI*x1)) + (pow(x2,2) - 10*cos(2*M_PI*x2));     //Rastrigin
        else if(fun==2)
                x.fitness= (418.9829*2) - x1*sin(sqrt(fabs(x1))) - x2*sin(sqrt(fabs(x2))); //schwefel
        else if(fun==3)
        {
                double z,ogkos=1000;
                //ο τύπος για τον όγκο του παραλληλογράμμου=x1*x2*z
                z=ogkos/(x1*x2);
                x.fitness= (2*(x1*z))+(2*(x2*z))+(2*(x1*x2));  
				// Το εμβαδό της παράπλευρής επιφάνειας ειναι το άθροισμα των όγκων των 6 επιφανειών 
        }
}


/* Η συνάρτηση HillClimb δέχεται ένα δείκτη ατόμου,
τον αριθμο των BITS και την συνάρτηση για την οποια εκετελείται.
Δεν επιστρέφει τίποτα. Η βασική ιδέα αυτής της συνάρτησης ειναι 
να βοηθάει τον γενετικό αλγόριθμο να ξεπερνάει τα τοπικά βέλτιστα
έτσι ώστε να οδηγηθεί στο πραγματικό βέλτιστο.
*/

void HillClimb(atom & x, int BITS, int fun)
{

        int i,j;
        int steps[4]= {10,-10,1,-1};
        atom oldx;
        oldx = x;
        for (j=0;j<VARS;j++)
                for (i=0;i<4;i++)
                        if((x.geno[j]+steps[i])>=0 && x.geno[j]+steps[i]<pow(2,BITS))
                        {
                                x.geno[j]=x.geno[j]+steps[i];
                                Fitness(x, BITS, fun);
                                if(x.fitness<oldx.fitness)
                                        oldx=x;
                                else
                                        x=oldx;
                        }

}

/* Η συνάρτηση Display δέχεται ένα δείκτη ατόμου,
τον αριθμο των BITS, έναν ακέραιο αριθμό και έναν δείκτη αρχείου.
Δεν επιστρέφει τίποτα. Η βασική ιδέα αυτής της συνάρτησης ειναι να
γράγει τα αποτεέσματα του αλγορίθμου στο αρχείο που ο χρήστης επέλεξε.
*/

void Display(atom * x, int N, int BITS, FILE *f1)
{
       int i,j;
        for (i=0;i<N;i++) {
                fprintf(f1,"Atom %2i : ",i);
                for (j=0;j<VARS;j++) {
                        fprintf(f1, "%s ",Int2Str(x[i].geno[j], BITS));
                }
                for (j=0;j<VARS;j++) {
                        fprintf(f1,"%5i ",x[i].geno[j]);
                }
                for (j=0;j<VARS;j++) {
                        fprintf(f1,"%10.7lf  ",x[i].pheno[j]);
                }
                if(BasicForm->Problem->ItemIndex==0)
                        fprintf(f1,"f= %10.7lf \n",x[i].fitness*(-1));
                else
                        fprintf(f1,"f= %10.7lf \n",x[i].fitness);
        }
}

/* Η συνάρτηση Roulette δέχεται ένα δείκτη ατόμου,
και έναν ακέραιο αριθμό. Επιστρέφει έναν ακέραιο αριθμό. 
Η βασική ιδέα αυτής της συνάρτησης ειναι ο τροχός της ρουλέτας δηλαδή
η μέθοδος της επιλογής των γονέων που χρησιμοιπούμε στον αλγόριθμο.
*/

int Roulette(atom * x, int N)
{
        double sum,sum2=0,sumrnd,max_fs,min_fs,s;
        int i;
        sum=0;
        max_fs=x[0].fitness;

        s=0;
        //Δυναμική δήλωση ενός δείκτη απο Ν πραφματικούς αριθμούς ?? 
		double *rev= new double[N];

        
        //Εύρεση και αποθήκευση της μεγαλύτερης ποιότητας των υποψηφίων γονιών
		for (i=1;i<N;i++)
                if(max_fs<x[i].fitness)
                        max_fs=x[i].fitness;

        
        //Για να αποκλείσουμε την περίπτωση όπου το max_fs θα ειναι 0 προσθέτουμε το 0.1
		s=max_fs+0.1;

        
		//Αποθήκευση των νέων ποιοτήτων στον πίνακα rev
        for (i=0;i<N;i++)
                rev[i]=s-x[i].fitness;

     
		//Εύρεση του αθροίσματος των νέων ποιοτήτων
        for (i=0;i<N;i++)
                sum+=rev[i];

		//Εύρεση ενός τυχαίου αριθμού απο 0 εώς sum
        sumrnd=rnd()*sum;

        for (i=0;i<N;i++)
        {
                sum2+=rev[i];     //Αποθήκευση του αθροίσματος των νέων ποιοτήτων
                if(sum2>sumrnd) break; //Αν το νέο άθροισμα ειναι μεγαλύτερο απο τον τυχαίο αριθμό επιστρέφει το συγκεκριμένο άθροισμα.
        }

        if (i==N)
        {
                AnsiString st,st2;
                st.printf("sum=%lf sumrnd=%lf sum2=%lf max=%lf min=%lf s=%lf\n",sum,sumrnd,sum2,max_fs,min_fs,s);
                for (int j=0 ; j<N ; j++) {st2.printf("%lf ",x[j].fitness); st=st+st2; }
                ShowMessage(st);
        }

        //Αποδέσμευση του δείκτη για αποφυγή προβληματων στην μνήμη.
        delete [] rev;

        return i;
}

/* Η συνάρτηση FindBest δέχεται ένα δείκτη ατόμου,
και έναν ακέραιο αριθμό. Επιστρέφει έναν ακέραιο αριθμό. 
Την χρησιμοιπούμε για να βρούμε την καλύτερη λύση κάθε γενιάς.
*/

int FindBest(atom *x, int N)
{
        int i,Best=0;
        double BestFit=x[0].fitness;
        for (i=1;i<N;i++)
                if (x[i].fitness<BestFit)
        {
                BestFit=x[i].fitness;
                Best=i;
        }
        return Best;
}

/* Η συνάρτηση UpdateBeliefSpace δέχεται ένα άντικείμενο τύπου ατομου,
έναν πίνακα τύπου ατόμου και έναν ακέραιο αριθμό. Δεν επιστρέφει τίποτα.
Η συγκεκριμένη συνάρτηση καλείται για την εισαγωγή και ταξινόμηση της καλύτερης 
λύσης στον χώρο μνήμης και στην περίπτωση που έχει γεμίσει ο χώρος μνήμης διαγράφει 
τις κακές λύσεις για να εισάγει τις καλύτερες.
*/

void UpdateBeliefSpace(atom best, atom BeliefSpace[], int B)
{
        bool flag= false;
        int sum=0;
		//Έλεγχος αν τα γενότυπα του Βest υπάρχουν ήδη σε κάποιο άτομο του χώρου μνήμης.
        for(int j=0; j<flagBS; j++)
        {
                for(int k=0; k<VARS; k++)
                        if(best.geno[k] == BeliefSpace[j].geno[k])
                               sum++;

                 if(VARS == sum)
                        flag = true;

                 sum=0;
        }

       if(flagBS<B & flag==false)    //Γεμίζει και ταξινομεί τον πίνακα
       {
                BeliefSpace[flagBS]=best;
                for(int i = 0; i <flagBS; i++)
                        for(int j =0; j<flagBS-i; j++)
                                if(BeliefSpace[j].fitness>BeliefSpace[j+1].fitness)
                                {
                                        atom temp=BeliefSpace[j];
                                        BeliefSpace[j]=BeliefSpace[j+1];
                                        BeliefSpace[j+1]=temp;
                                }
               flagBS++;

       }
       else if(flagBS>=B & flag==false)  //Όταν γεμίσει ο πίνακας κάνει αντικατάσταση
       {
                int i=B-1;
                while(best.fitness < BeliefSpace[i].fitness && i>=0)
                {
                                if(i>0)
                                        BeliefSpace[i]=BeliefSpace[i-1];
                                i--;

                }
                if(i!=B-1)
                        BeliefSpace[i+1]=best;
        }




}

/* Η συνάρτηση HammDist δέχεται δύο ακέραιους αριθμούς.
Επιστρέφει έναν ακέραιο αριθμό. Επιστρέφει μία ακέραιη 
τιμή η οποία ειναι η απόσταση (διαφορά) των δύο γονοτύπων
Ο τελεστής &= Bitwise κάνει την σύγκριση bit pros bit
της ακολουθίας που παράχτηκε απο την XOR των δύο γονοτύπων, 
επιστρέφει true μόνο αν υπάρχει μονάδα στην ίδια θέση
και στης δύο ακολουθίες αλλιώς επιστρέφει false
*/

int HammDist(int gen1, int gen2)
{
        int dist=0;
        int val=gen1^gen2;
        while(val)
        {
                ++dist;
                val &=val-1;  
        }                     
        return dist;          
}

/* Η συνάρτηση FindDistance δέχεται ένα αντικείμενο τύπου ατόμου, 
δύο ακέραιους αριθμούς καί τον χώρο μνήμης. Επιστρέφει μια ακέραιη τιμή 
Την χρησιμοιπούμε για να υπολογίσουμε την πιο κοντινή λύση που 
υπάρχει στον χώρο μνήμης σε σύγκριση με το άτομο που δέχεται σαν όρισμα.
*/
int FindDistance(atom best,int point, atom BeliefSpace[], int B)
{
         int sum =0,min =0,position=-1;
         int endpoint;
         if(point<B)
                endpoint=point;
         else
                endpoint=B;

         for(int i=0; i<endpoint; i++)
         {
			//Άθροισμα των διαφορών των γονοτύπων ανάμεσα στην καλύτερη λύση και της αντίστηχης του χώρου μνήμης
                for(int j=0; j<VARS; j++)
                        sum=sum+HammDist(best.geno[j],BeliefSpace[i].geno[j]);
                if(i==0 || sum<min)
                {
                        min=sum;
                        position=i;

                }
                sum=0;
        }

        return position;
}

/*Η συνάρτηση Compare δέχεται ένα αντικείμενο τύπου ατόμου, 
τρείς ακέραιους αριθμούς καί τον χώρο μνήμης. Την χρησιμοιπούμε
για να ελενξουμε αν η υπάρχουσα καλύτερη λύση ειναι καλύτερη απο 
την καλύτερη λύση που θα δημιουργήσουμε μετά των ανασυνδυασμό αυτής 
με το κατάλληλο άτομο του χώρου μνήμης και επιστρέφει αυτην την λύση.
*/
atom Compare(atom best,int position, int BITS, int fun,atom BeliefSpace[])
{
        atom temp;

        temp=Crossover(best,BeliefSpace[position],BITS);
        Fitness(temp, BITS, fun);

        if(best.fitness<temp.fitness) 
                return best;
        else
                return temp;
}

/* Η συνάρτηση cleanFlagBS δεν δέχεται τίποτα σαν όρισμα
και δεν επιστρέφει τίποτα. Την χρησιμοιπούμε για να αρχοικοποιήσουμε
με μηδεν την μεταβλητή που μας ......*/

void cleanFlagBS()
{
        flagBS=0;
}



/* Η συνάρτηση algorithm δεν δέχεται ορίσματα και
δεν επιστρέφει τίποτα. Ειναι η βασική συνάρτηση της
εφαρμογής, καθώς ειναι η λογική όλου του αλγορίθμου.
*/
void algorithm()
{


       //Αρχικοποίηση μεταβλητών
        int N=BasicForm->Population->Text.ToInt();
        int g=BasicForm->Generations->Text.ToInt();
        int B=BasicForm->Beliefspace->Text.ToInt();
        int BITS=BasicForm->Bits->Text.ToInt();
        int fun=BasicForm->Problem->ItemIndex;
        double mutation=BasicForm->Mutation->Text.ToDouble();
        int paralagi = BasicForm->Variation->ItemIndex;

        //Δήλωση μεταβλητών
        atom* BeliefSpace= new atom[B];
        atom *Par= new atom[N];
        atom *Pop= new atom[N];

        int i,j,Best,child,gen,position,p1,p2;
        FILE *f1;

        srand((unsigned)time(NULL));

        //Αρχικοποίηση του αρχικού πληθυσμού των γονέων
        for (i=0;i<N;i++)
                for(j=0;j<VARS;j++)
                        Par[i].geno[j]=random(pow(2,BITS));
        //Αξιολόγηση των γονέων
        for (i=0;i<N;i++)
                Fitness(Par[i], BITS, fun);

        //Δημιουργία του αρχείου για τα αποτελέσματα του αλγορίθμου
        if(BasicForm->Savefile->Checked)
        {
                if(BasicForm->EditName->Text!="")
                {
                    String name=BasicForm->EditName->Text + ".txt";
                    f1=fopen(name.c_str(),"w");
                }
                else
                        f1=fopen("results.txt","w");

                fprintf(f1,"Population: %i    Generations: %i Belief space index: %i \n", N, g, B);
                fprintf(f1,"Number of Bits: %i    Mutation Rate: %f     Function Problem: %s  \n", BITS, mutation, BasicForm->Problem->Text);
                fprintf(f1,"Variation: %s    ", BasicForm->Variation->Text);

                if(BasicForm->Hillclimb->Checked)
                        fprintf(f1,"Hill Climb: YES\n\n");
                else
                       fprintf(f1,"Hill Climb: NO\n\n");

                fprintf(f1,"Atoms      Binary0    Binary1   Geno0  Geno1  Pheno0     Pheno1      Fitness \n\n");
                fprintf(f1,"Arxikos Plithismos\n");
                Display(Par,N,BITS,f1);
        }

		//Η κύρια επανάληψη των γενεών
         for (gen=0;gen<g;gen++)
         {
                if(BasicForm->Savefile->Checked)
                        fprintf(f1,"Generation= %i \n",gen);

                Best=FindBest(Par, N);
                Pop[0]=Par[Best];
				//Η επανάληψη για την δημιουργία των απογόνων
                for (child=1; child<N; child++)
                {

                        //Επιλογή γονέων με την χρήση της Ρουλέτας
                        p1=Roulette(Par, N);
                        p2=Roulette(Par, N);

                        //Ανασυνδυασμός των γονέων
                        Pop[child]= Crossover(Par[p1],Par[p2], BITS);

                        //Χρήση του τελεστή της Μετάλλαξης στον απόγονο
                        Pop[child]= Mutation (Pop[child], mutation, BITS);

                        //Περιπτώσεις 2 και 3 σε περίπτωση επιλογής απο τον χρήστη
                        if(paralagi==1)
                        {
                                int position=FindDistance(Pop[child],gen,BeliefSpace,B);
                                if (position!=-1)
                                        Pop[child]=Compare(Pop[child],position, BITS, fun, BeliefSpace);

                        }
                        else if(paralagi==2)
                        {
                                position=FindDistance(Pop[child],gen,BeliefSpace,B);
                                if (position!=-1)
                                        Pop[child]=Crossover(Pop[child],BeliefSpace[position], BITS);
                        }

                        //Αξιολόγηση του απογόνου
                        Fitness(Pop[child], BITS, fun);
                }

				//Βρίσκουμε την θέση του καλύτερου απογόνου
                Best=FindBest(Pop, N);
				//Χρήση του τελεστή αναρήχησης αν επιλεγεί απο τον χρήστη
                if(BasicForm->Hillclimb->Checked)
                        HillClimb(Pop[Best], BITS, fun);

				//Εύρεση της θέσης ......
                position=FindDistance(Pop[Best],gen,BeliefSpace,B);
                if(position!=-1)
                        Pop[Best]=Compare(Pop[Best],position, BITS, fun, BeliefSpace);

				//Γέμισμα ή ενημέρωσει του χώρου μνήμης
                UpdateBeliefSpace(Pop[Best],BeliefSpace,B);

				//Εμφάνιση των αποτελεσμάτων στην δεύτερη φόρμα και στο αρχείο
                if(BasicForm->Savefile->Checked)
                {
                        Display (Pop, N, BITS, f1);
                        fprintf(f1,"Best After Culture Algorithm \n");
                }

                ViewForm->Table->Cells[0][gen+1]=gen;
                for (j=0;j<VARS;j++) {
                        if(BasicForm->Savefile->Checked)
                                fprintf(f1,"    %s  ",Int2Str(Pop[Best].geno[j],BITS));
                       ViewForm->Table->Cells[j+1][gen+1]=Int2Str(Pop[Best].geno[j], BITS);
                }
                for (j=0;j<VARS;j++)
                {
                        if(BasicForm->Savefile->Checked)
                                fprintf(f1,"%5i ",Pop[Best].geno[j]);
                       ViewForm->Table->Cells[3+j][gen+1]=Pop[Best].geno[j];
                }

                for (j=0; j<VARS; j++)
                {
                        if(BasicForm->Savefile->Checked)
                                fprintf(f1,"%10.7lf  ",Pop[Best].pheno[j]);
                        std::stringstream pheno;
                        pheno<<std::fixed<<std::setprecision(10)<< Pop[Best].pheno[j];
                        ViewForm->Table->Cells[5+j][gen+1]=pheno.str().c_str(); 
                }

                if(BasicForm->Savefile->Checked)
                        fprintf(f1,"f= %10.7lf \n\n",Pop[Best].fitness);


                std::stringstream fitness;
                fitness<<std::fixed<<std::setprecision(10)<< Pop[Best].fitness;
                ViewForm->Table->Cells[7][gen+1]=fitness.str().c_str();
                //ViewForm->Table->Cells[7][gen+1]=  Pop[Best].fitness;

                //Αντικατάσταση των γονέων απο τους απογόνους
                for (i=0;i<N;i++)
                  Par[i]=Pop[i];

         }

         //Εμφάνιση του τελικού χώρου μνήμης στην δεύτερη φόρμα
         for(i=0; i<flagBS; i++)
                if(BasicForm->Problem->ItemIndex==0)
                {
                        std::stringstream bf1;
                        bf1<<std::fixed<<std::setprecision(10)<< Double(BeliefSpace[i].fitness)*(1);
                        ViewForm->LabelBeliefS->Caption=ViewForm->LabelBeliefS->Caption + "\n" + bf1.str().c_str();
                }
                else
                {
                        std::stringstream bf;
                        bf<<std::fixed<<std::setprecision(10)<< Double(BeliefSpace[i].fitness);
                        ViewForm->LabelBeliefS->Caption=ViewForm->LabelBeliefS->Caption + "\n" + bf.str().c_str();
                }
		//Εμφάνιση του τελικού χώρου μνήμης στο αρχείο	
         if(BasicForm->Savefile->Checked)
         {
                fprintf(f1,"Belief Space \n");
                for(i=0; i<flagBS; i++)
                         if(BasicForm->Problem->ItemIndex==0)
                                fprintf(f1,"%10.7lf \n", BeliefSpace[i].fitness*(1));
                         else
                                fprintf(f1,"%10.7lf \n", BeliefSpace[i].fitness);

                fclose(f1);
         }


         //Αποδέσμευση της μνήμης απο τα αντικείμενα
         delete Par;
         delete Pop;
         delete BeliefSpace;
}


//---------------------------------------------------------------------------





