#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{

    float v[3][2];

} triangle;

typedef struct
{

    float punto[2], vd[2];

} recta;

recta bisectriu(float[2], float[2], float[2]);
void mitjanes3(triangle, recta *, recta *, recta *);
recta mediatriu(float[2], float[2]);
recta *altures3(triangle);
int intersec2rectes(recta, recta, float[2]);
void escriure1recta(char *, recta);
void escriure1punt(char *, float[2]);

int main()
{
    triangle vertices;

    int i, j, a1, a2, a3;
    float area, base, alt, v1v2[2], inc1[2], inc2[2], inc3[2], bar1[2], bar2[2], bar3[2], circ1[2], circ2[2], circ3[2], orto1[2], orto2[2], orto3[2], alineats;
    recta b1, b2, b3, media1, media2, media3, euler,tmp;
    int ba1, ba2, ba3, i1, i2, i3, c1, c2, c3;
    recta * alturas, *mitj1, *mitj2, *mitj3;
    char *nombre[25]=
    
    {
        "bisectriu 1",
        "bisectriu 2",
        "bisectriu 3",
        "interseccio de bisectrius 1-2",
        "interseccio de bisectrius 2-3",
        "interseccio de bisectrius 3-1",
        "mitjana 1",
        "mitjana 2",
        "mitjana 3",
        "interseccio de mitjanes 1-2",
        "interseccio de mitjanes 2-3",
        "interseccio de mitjanes 3-1",
        "mediatriu 1",
        "mediatriu 2",
        "mediatriu 3",
        "interseccio de mediatrius 1-2",
        "interseccio de mediatrius 2-3",
        "interseccio de mediatrius 3-1",
        "altura 1",
        "altura 2",
        "altura 3",
        "interseccio d'altures 1-2",
        "interseccio d'altures 2-3",
        "interseccio d'altures 3-1",
        "recta d'Euler"
    };

    /* leemos los vertices*/
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%f", &vertices.v[i][j]);
        }
    }
    
    mitj1= (recta *)malloc(1 * sizeof(recta));
    mitj2= (recta *)malloc(1 * sizeof(recta));
    mitj3= (recta *)malloc(1 * sizeof(recta));
    
    /* procedemos a calcular el area y miramos que sea positiva
        la base sera el modulo del vd entre v1 y v2 y la altura
        el modulo del vd de alturas[0]
        */

    v1v2[0]=vertices.v[1][0]-vertices.v[0][0];
    v1v2[1]=vertices.v[1][1]-vertices.v[0][1];
    base= sqrt(pow(v1v2[0], 2) + pow(v1v2[1], 2));

    alturas= altures3(vertices);
    alt= sqrt(pow(alturas[0].vd[0], 2) + pow(alturas[0].vd[1], 2));
    area= (base*alt)/2;

    printf("comprovacio de si el triangle es degenerat:\n");
    

    if (area<=0)
    {
        printf(" triangle degenerat\n");
        exit(1);
    } 
    
    printf(" area= %+f \n", area);
    printf("\n");
    printf(" comprovacio que les 3 bisectrius son concurrents: incentre \n");

    b1= bisectriu(vertices.v[0], vertices.v[1], vertices.v[2]);
    b2= bisectriu(vertices.v[1], vertices.v[0], vertices.v[2]);
    b3= bisectriu(vertices.v[2], vertices.v[1], vertices.v[0]);
    
    

    escriure1recta(nombre[0], b1);
    escriure1recta(nombre[1], b2);
    escriure1recta(nombre[2], b3);

   i1= intersec2rectes(b1,b2,inc1);
   i2= intersec2rectes(b2,b3,inc2);
   i3= intersec2rectes(b3,b1,inc3);

   
   
   if(i1!=0 || i2!=0 || i3!=0){

       printf(" no se cruzan en un unico punto \n");
       exit(1);
   }
   
    escriure1punt(nombre[3], inc1);
    escriure1punt(nombre[4], inc2);
    escriure1punt(nombre[5], inc3);

    printf("\n");
    printf(" comprovacio que les 3 mitjanes son concurrents: baricentre \n");

    mitjanes3(vertices, mitj1, mitj2, mitj3);
    
    tmp.punto[0]=mitj1->punto[0];
    tmp.punto[1]=mitj1->punto[1];
    tmp.vd[0]=mitj1->vd[0];
    tmp.vd[0]=mitj1->vd[0];    
    escriure1recta(nombre[6], tmp);
    
    tmp.punto[0]=mitj2->punto[0];
    tmp.punto[1]=mitj2->punto[1];
    tmp.vd[0]=mitj2->vd[0];
    tmp.vd[0]=mitj2->vd[0];   
    escriure1recta(nombre[7], tmp);
    
    tmp.punto[0]=mitj3->punto[0];
    tmp.punto[1]=mitj3->punto[1];
    tmp.vd[0]=mitj3->vd[0];
    tmp.vd[0]=mitj3->vd[0];   
    escriure1recta(nombre[8], tmp);

    ba1= intersec2rectes(*mitj1,*mitj2,bar1);
    ba2= intersec2rectes(*mitj2,*mitj3,bar2);
    ba3= intersec2rectes(*mitj3,*mitj1,bar3);

   
   
   if(ba1!=0 || ba2!=0 || ba3!=0){

       printf(" no se cruzan en un unico punto \n");
       exit(1);
   }
   
    escriure1punt(nombre[9], bar1);
    escriure1punt(nombre[10], bar2);
    escriure1punt(nombre[11], bar3);


    printf("\n");
    printf(" comprovacio que les 3 mediatrius son concurrents: circumcentre \n");

    media1= mediatriu(vertices.v[0], vertices.v[1]);
    media2= mediatriu(vertices.v[1], vertices.v[2]);
    media3= mediatriu(vertices.v[2], vertices.v[0]);


    escriure1recta(nombre[12], media1);
    escriure1recta(nombre[13], media2);
    escriure1recta(nombre[14], media3);

    c1= intersec2rectes(media1,media2,circ1);
    c2= intersec2rectes(media2,media3,circ2);
    c3= intersec2rectes(media3,media1,circ3);

   
   
   if(c1!=0 || c2!=0 || c3!=0){

       printf(" no se cruzan en un unico punto \n");
       exit(1);
   }
   
    escriure1punt(nombre[15], circ1);
    escriure1punt(nombre[16], circ2);
    escriure1punt(nombre[17], circ3);


    printf("\n");
    printf(" comprovacio que les 3 altures son concurrents: ortocentre \n");

    escriure1recta(nombre[18], alturas[0]);
    escriure1recta(nombre[19], alturas[1]);
    escriure1recta(nombre[20], alturas[2]);
    
    a1= intersec2rectes(alturas[0],alturas[1],orto1);
    a2= intersec2rectes(alturas[1],alturas[2],orto2);
    a3= intersec2rectes(alturas[2],alturas[0],orto3);


   
   if(a1!=0 || a2!=0 || a3!=0){

       printf(" no se cruzan en un unico punto \n");
       exit(1);
   }
   
    escriure1punt(nombre[21], orto1);
    escriure1punt(nombre[22], orto2);
    escriure1punt(nombre[23], orto3);


    printf("\n");
    printf(" comprovacio que baric., circum. i ortoc. estan alineats: \n");

    alineats= (circ1[1]-bar1[1])*(orto1[0]-bar1[0])-(circ1[0]-bar1[0])*(orto1[1]-bar1[1]);
    printf("(cir1-bar1)*(ort0-bar0)-(cir0-bar0)*(ort1-bar1) = %+f \n", alineats);
    
    euler.punto[0]= bar1[0];
    euler.punto[1]= bar1[1];

    euler.vd[0]= circ1[0]-bar1[0];
    euler.vd[1]= circ1[1]-bar1[1];

    escriure1recta(nombre[24], euler);

    
    free(alturas);
    free(mitj1);
    free(mitj2);
    free(mitj3);
    /*free(nombre);*/

    return 0;
}

recta bisectriu(float v1[2], float v2[2], float v3[2])
{
    recta bisectriz, r1, r2;
    float A1, B1, C1, A2, B2, C2, x, y, p[2], raiz1, raiz2, coefx, coefy;
    

    /* el punto de la recta es el vertice que bisecamos */
    bisectriz.punto[0]=v1[0];
    bisectriz.punto[1]=v1[1];

    /* por la definición de bisectriz, siendo r1 y r2 las rectas que se cruzan en el vertice 
    a bisectar (v3v1 y v2v1), tenemos que la distancia de un punto cualquiera P de la bisectriz
    a r1 ha de ser igual a la distancia de P a r2
    Hacemos los calculos necesarios igualando las dos distancias: pasamos de ecuacion parametrica a ecuacion general
    y aplicamos la formula de distancia punto-recta*/

    r1.punto[0]=v3[0];
    r1.punto[1]=v3[1];      /* puntos de las rectas r1 y r2*/
    r2.punto[0]=v2[0];
    r2.punto[1]=v2[1];
  
    r1.vd[0]=v1[0]-v3[0];
    r1.vd[1]=v1[0]-v3[1];      /* vectores directos de las rectas r1 y r2*/
    r2.vd[0]=v1[0]-v2[0];
    r2.vd[1]=v1[1]-v2[1];
   
/* pasamos de recta parametrica a recta general, Ax+By+C=0 donde 
        A= vd[1]
        B= vd[0]
        C= vd[0]*punto[1]-vd[1]*punto[0]    */
    

    A1= r1.vd[1];
    B1= r1.vd[0];
    C1= r1.vd[0]*r1.punto[1]-r1.vd[1]*r1.punto[0];
                                                            /* r1 y r2 en forma general*/
    A2= r2.vd[1];
    B2= r2.vd[0];
    C2= r2.vd[0]*r1.punto[1]-r1.vd[1]*r1.punto[0];

    /* igualamos las dos distancias mediante la formula distancia punto-recta =
                    |Ax+By+C|/sqrt(pow(A,2)+pow(B,2)) y obtendremos una recta donde los coeficientes de 
                    x,y seran vd[1],vd[0] respectivamente


                    y*(coefy)=x*coefx + raiz1*C2 - raiz2*C1
        */

    
    raiz1=sqrt(pow(A1,2)+pow(B1,2));
    raiz2=sqrt(pow(A2,2)+pow(B2,2));
    coefx=(A2*raiz1 - A1*raiz2);
    coefy= (raiz2*B1 - B2*raiz1);

    
    bisectriz.vd[0]= coefy;
    bisectriz.vd[1]= coefx;

        return bisectriz;

}

void mitjanes3(triangle vertices, recta *mitj1, recta *mitj2, recta *mitj3)
{

    float m[3][2];
    int k, i, j;

    

    /* rellenamos la ,atriz con los tres puntos medios*/
    for (i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            k = 0; /* para calcular el punto medio entre v3 y v1*/
        }
        else
        {
            k = i + 1; /* para calcular el punto medio entre v1 y v2, y v2 y v3*/
        }
        for (j = 0; j < 2; j++)
        {
            m[i][j] = (vertices.v[i][j] + vertices.v[k][j]) / 2;
        }
    }

    for (i = 0; i < 2; i++)
    {
        mitj1->vd[i] = vertices.v[2][i] - m[0][i];
        mitj2->vd[i] = vertices.v[0][i] - m[1][i];
        mitj3->vd[i] = vertices.v[1][i] - m[2][i];
        mitj1->punto[i] = m[0][i];
        mitj2->punto[i] = m[1][i];
        mitj3->punto[i] = m[2][i];
    }
}

recta mediatriu(float v1[2], float v2[2])
{

    recta r;

    r.punto[0] = (v1[0] + v2[0]) / 2;
    r.punto[1] = (v1[1] + v2[1]) / 2;

    r.vd[0] = -(v2[1] - v1[1]);
    r.vd[1] = (v2[0] - v1[0]);

    return r;
}

recta *altures3(triangle t)
{
    recta * alturas= (recta *)malloc(3 * sizeof(recta));

    int i, j;

    for (i = 0; i < 3; i++)
    {
        alturas[i].punto[0] = t.v[i][0];
        alturas[i].punto[1] = t.v[i][1];

        alturas[i].vd[0] = -(t.v[(i + 1) % 3][1] - t.v[(i + 2) % 3][1]);
        alturas[i].vd[1] = (t.v[(i + 1) % 3][0] - t.v[(i + 2) % 3][0]);
    }

    return alturas;
}


int intersec2rectes(recta r1, recta r2, float puntinter[2])
{
    float x, y, m1, m2, n1, n2;


    /* primero distinguimos entre secante o no, por lo tanto mismo pendiente o no, vector director proporcional o no*/
    
    if (r1.vd[0]/r2.vd[0]==r1.vd[1]/r2.vd[1])
    {
        return 1;
    }
 

    /*
        pasamos las dos rectas a ecuacion explicita
    yr1 = (r1.vd[1]*x - r1.punto[0]*r1.vd[1]+ r1.punto[1]*r1.vd[0])/r1.vd[0];
    yr2 = (r2.vd[1]*x - r2.punto[0]*r2.vd[1]+ r2.punto[1]*r2.vd[0])/r2.vd[0];

    las igualamos 

    tenemos yr1= m1x+n1, yr2=m2x+n2
            m1x+n1=m2x+n2 y por tanto
            x= (n2-n1)(m1-m2)

*/
m1=r1.vd[1]/r1.vd[0];
n1= (- r1.punto[0]*r1.vd[1]+ r1.punto[1]*r1.vd[0])/r1.vd[0];
m2=r2.vd[1]/r2.vd[0];
n2=(- r2.punto[0]*r2.vd[1]+ r2.punto[1]*r2.vd[0])/r2.vd[0];
    
  x= (n2-n1)*(m1-m2);
  y= m1*x+n1;
    
    puntinter[0]=x;
    puntinter[1]=y;

    

    return 0;
}


void escriure1recta(char * nombre, recta r){

    /*nombre= (char *)malloc(40 * sizeof(char));*/

printf(" %s: (%+f, %+f) + t(%+f, %+f) \n", nombre, r.punto[0], r.punto[1], r.vd[0], r.vd[1]);


}

void escriure1punt(char * nombre, float punto[2]){
    /*nombre= (char *)malloc(40 * sizeof(char));*/

printf(" %s: (%+f, %+f) \n", nombre, punto[0], punto[1]);

}