#include "library.h"
#include "mpi_nnie.h"
#include <iostream>
#include <plthook.h>

extern "C"{
HI_S32 HOOK_HI_MPI_SVP_NNIE_LoadModel(const SVP_SRC_MEM_INFO_S *pstModelBuf, SVP_NNIE_MODEL_S *pstModel){
    static int idx = 0;
    auto pFile = fopen( (std::to_string(idx++)+".wk").c_str(),"w" );
    if( NULL == pFile ){
        printf( "open failure\n");
    }else{
        fwrite(reinterpret_cast<const void *>(pstModelBuf->u64VirAddr), 1, pstModelBuf->u32Size, pFile);
    }
    fclose(pFile);
    HI_S32 ret = HI_MPI_SVP_NNIE_LoadModel(pstModelBuf,pstModel);
    return ret;
}

int hook() {
    plthook_t *plthook;
    if (plthook_open(&plthook,NULL) != 0) {
        printf("plthook_open error: %s\n", plthook_error());
        return -1;
    }
    if (plthook_replace(plthook, "HI_MPI_SVP_NNIE_LoadModel", (void*)HOOK_HI_MPI_SVP_NNIE_LoadModel, NULL) != 0) {
        printf("plthook_replace error: %s\n", plthook_error());
        plthook_close(plthook);
        return -1;
    }
    plthook_close(plthook);
    return 0;
}
}


