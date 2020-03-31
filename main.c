
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "metis.h"

int main( int argc, char *argv[] ) {

   int ier; // short, int, long?

   // TEST: EXAMPLE FROM MANUAL

   // m = number of edges (m = 22, 2m = 44)
   // n = number of vertices (n = 15, n+1 = 16)

   idx_t nvtxs = 15;
   idx_t ncon = 1;
   idx_t xadj[16] = {0, 2, 5, 8, 11, 13, 16, 20, 24, 28,
                   31, 33, 36, 39, 42, 44};
   idx_t adjncy[44] = {1, 5, 0, 2, 6, 1, 3, 7, 2, 4,
                     8, 3, 9, 0, 6, 10, 1, 5, 7, 11,
                     2, 6, 8, 12, 3, 7, 9, 13, 4, 8,
                     14, 5, 11, 6, 10, 12, 7, 11, 13, 8,
                     12, 14, 9, 13};
   idx_t *vwgt = NULL;
   idx_t *vsize = NULL;
   idx_t *adjwgt = NULL;
   idx_t nparts = 3;
   real_t *tpwgts = NULL;
   real_t ubvec = 1.001; // float *ubvec = NULL;
   idx_t *options = NULL;
   idx_t objval;
   idx_t part[15];

//      ! -- Options for the ParMETIS routine
//      options(:)= 0
//      options(1)= 1  ! Set to 1 to interpret the following options
//      options(3)= 15 ! Random number seed for the routine
//      options(4)= PMET3_PSR_UNC ! For ParMetis 3.2.0 or higher
//      if (debug) then
//         options(2)= 7  ! _TIME(1), _INFO(2), and _PROGRESS(4).  See parmetis.h for options
//      endif

//   OPTIONS
//   int options[METIS_NOPTIONS];

//   The following options are valid for METIS_PartGraphKway:
//   options[METIS_OPTION_OBJTYPE]
//   options[METIS_OPTION_CTYPE]
//   options[METIS_OPTION_IPTYPE]
//   options[METIS_OPTION_RTYPE]
//   options[METIS_OPTION_NO2HOP]
//   options[METIS_OPTION_NCUTS]
//   options[METIS_OPTION_NITER]
//   options[METIS_OPTION_UFACTOR]
//   options[METIS_OPTION_MINCONN]
//   options[METIS_OPTION_CONTIG] = 1;
//   options[METIS_OPTION_SEED]
//   options[METIS_OPTION_NUMBERING] = 0; // C-style numbering is assumed that starts from 0
//   options[METIS_OPTION_DBGLVL] = 0; // The default value is 0 (no debugging/progress information)

   ier = METIS_PartGraphKway( &nvtxs, &ncon, xadj, adjncy,
                              vwgt, vsize, adjwgt, &nparts, tpwgts,
                              &ubvec, options, &objval, part); 

   // OUTPUT
   printf("ier: %d\n",ier);
   printf("objval: %d\n",objval);

   // DEBUGGING
#ifdef _DEBUG_
   printf("METIS_NOPTIONS: %d\n",METIS_NOPTIONS);
   printf("METIS_OK: %d\n",METIS_OK);
   printf("METIS_ERROR_INPUT: %d\n",METIS_ERROR_INPUT);
   printf("METIS_ERROR_MEMORY: %d\n",METIS_ERROR_MEMORY);
   printf("METIS_ERROR: %d\n",METIS_ERROR);
   // TESTING
//   printf("%d\n",METIS_OBJTYPE_CUT); // = 0
//   printf("%d\n",METIS_OBJTYPE_VOL); // = 1
#endif

   // print partition vector of the graph and objective value
   printf("\n");
   for(int i=0;i<3;++i) {
      for(int j=0;j<5;++j) {
         printf("%d ",part[5*i+j]);
      }
      printf("\n");
   }
   printf("\n");

   return(0);
}

