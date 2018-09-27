/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This code is an adaptation of the Lee algorithm's implementation originally included in the STAMP Benchmark
 * by Stanford University.
 *
 * The original copyright notice is included below.
 *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright (C) Stanford University, 2006.  All Rights Reserved.
 * Author: Chi Cao Minh
 *
 * =============================================================================
 *
 * Unless otherwise noted, the following license applies to STAMP files:
 *
 * Copyright (c) 2007, Stanford University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of Stanford University nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY STANFORD UNIVERSITY ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL STANFORD UNIVERSITY BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * =============================================================================
 *
 * maze.c
 *
 * =============================================================================
 */


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "coordinate.h"
#include "grid.h"
#include "lib/list.h"
#include "maze.h"
#include "lib/queue.h"
#include "lib/pair.h"
#include "lib/types.h"
#include "lib/vector.h"


/* =============================================================================
 * maze_alloc
 * =============================================================================
 */
maze_t* maze_alloc (){
    maze_t* mazePtr;

    mazePtr = (maze_t*)malloc(sizeof(maze_t));
    if (mazePtr) {
        mazePtr->gridPtr = NULL;
        mazePtr->workQueuePtr = queue_alloc(1024);
        mazePtr->wallVectorPtr = vector_alloc(1);
        mazePtr->srcVectorPtr = vector_alloc(1);
        mazePtr->dstVectorPtr = vector_alloc(1);
        assert(mazePtr->workQueuePtr &&
               mazePtr->wallVectorPtr &&
               mazePtr->srcVectorPtr &&
               mazePtr->dstVectorPtr);
    }

    return mazePtr;
}

/* =============================================================================
 * maze_free
 * =============================================================================
 */
void maze_free (maze_t* mazePtr){
    if (mazePtr->gridPtr != NULL) {
        grid_free(mazePtr->gridPtr);
    }
    assert(queue_isEmpty(mazePtr->workQueuePtr));
    queue_free(mazePtr->workQueuePtr);

    coordinate_t* coord;

    while((coord = vector_popBack(mazePtr->wallVectorPtr))) {
        coordinate_free(coord);
    }
    assert(vector_getSize(mazePtr->wallVectorPtr) == 0);
    vector_free(mazePtr->wallVectorPtr);

    while((coord = vector_popBack(mazePtr->srcVectorPtr))) {
        coordinate_free(coord);
    }
    assert(vector_getSize(mazePtr->srcVectorPtr) == 0);
    vector_free(mazePtr->srcVectorPtr);

    while((coord = vector_popBack(mazePtr->dstVectorPtr))) {
        coordinate_free(coord);
    }
    assert(vector_getSize(mazePtr->dstVectorPtr) == 0);
    vector_free(mazePtr->dstVectorPtr);

    free(mazePtr);
}


/* =============================================================================
 * addToGrid
 * =============================================================================
 */
static void addToGrid (grid_t* gridPtr, vector_t* vectorPtr, char* type){
    long i;
    long n = vector_getSize(vectorPtr);
    for (i = 0; i < n; i++) {
        coordinate_t* coordinatePtr = (coordinate_t*)vector_at(vectorPtr, i);
        // TODO validar ponto
    }
    grid_addPath(gridPtr, vectorPtr);
}

/* =============================================================================
 * maze_read
 * -- Return number of path to route
 * =============================================================================
 */

long maze_read (maze_t* mazePtr){
    
    /*
     * Parse input from stdin
     */
    long lineNumber = 0;
    long height = -1;
    long width  = -1;
    long depth  = -1;
    char line[256];
    list_t* workListPtr = list_alloc(&coordinate_comparePair);
    vector_t* wallVectorPtr = mazePtr->wallVectorPtr;
    vector_t* srcVectorPtr = mazePtr->srcVectorPtr;
    vector_t* dstVectorPtr = mazePtr->dstVectorPtr;
    

		
	//printf("stdin:%s",stdin);
	printf("fgets:%s", fgets(line, sizeof(line), stdin));
	
	return vector_getSize(srcVectorPtr);
}

/* =============================================================================
 * maze_checkPaths
 * =============================================================================
 */
bool_t maze_checkPaths (maze_t* mazePtr, list_t* pathVectorListPtr, bool_t doPrintPaths){
    grid_t* gridPtr = mazePtr->gridPtr;
    long width  = gridPtr->width;
    long height = gridPtr->height;
    long depth  = gridPtr->depth;
    long i;

    /* Mark walls */
    grid_t* testGridPtr = grid_alloc(width, height, depth);
    grid_addPath(testGridPtr, mazePtr->wallVectorPtr);

    /* Mark sources */
    vector_t* srcVectorPtr = mazePtr->srcVectorPtr;
    long numSrc = vector_getSize(srcVectorPtr);
    for (i = 0; i < numSrc; i++) {
        coordinate_t* srcPtr = (coordinate_t*)vector_at(srcVectorPtr, i);
        grid_setPoint(testGridPtr, srcPtr->x, srcPtr->y, srcPtr->z, 0);
    }

    /* Mark destinations */
    vector_t* dstVectorPtr = mazePtr->dstVectorPtr;
    long numDst = vector_getSize(dstVectorPtr);
    for (i = 0; i < numDst; i++) {
        coordinate_t* dstPtr = (coordinate_t*)vector_at(dstVectorPtr, i);
        grid_setPoint(testGridPtr, dstPtr->x, dstPtr->y, dstPtr->z, 0);
    }

    /* Make sure path is contiguous and does not overlap */
    long id = 0;
    list_iter_t it;
    list_iter_reset(&it, pathVectorListPtr);
    while (list_iter_hasNext(&it, pathVectorListPtr)) {
        vector_t* pathVectorPtr = (vector_t*)list_iter_next(&it, pathVectorListPtr);
        long numPath = vector_getSize(pathVectorPtr);
        long i;
        for (i = 0; i < numPath; i++) {
            id++;
            vector_t* pointVectorPtr = (vector_t*)vector_at(pathVectorPtr, i);
            /* Check start */
            long* prevGridPointPtr = (long*)vector_at(pointVectorPtr, 0);
            long x;
            long y;
            long z;
            grid_getPointIndices(gridPtr, prevGridPointPtr, &x, &y, &z);
            if (grid_getPoint(testGridPtr, x, y, z) != 0) {
                grid_free(testGridPtr);
                return FALSE;
            }
            coordinate_t prevCoordinate;
            grid_getPointIndices(gridPtr,
                                 prevGridPointPtr,
                                 &prevCoordinate.x,
                                 &prevCoordinate.y,
                                 &prevCoordinate.z);
            long numPoint = vector_getSize(pointVectorPtr);
            long j;
            for (j = 1; j < (numPoint-1); j++) { /* no need to check endpoints */
                long* currGridPointPtr = (long*)vector_at(pointVectorPtr, j);
                coordinate_t currCoordinate;
                grid_getPointIndices(gridPtr,
                                     currGridPointPtr,
                                     &currCoordinate.x,
                                     &currCoordinate.y,
                                     &currCoordinate.z);
                if (!coordinate_areAdjacent(&currCoordinate, &prevCoordinate)) {
                    grid_free(testGridPtr);
                    return FALSE;
                }
                prevCoordinate = currCoordinate;
                long x = currCoordinate.x;
                long y = currCoordinate.y;
                long z = currCoordinate.z;
                if (grid_getPoint(testGridPtr, x, y, z) != GRID_POINT_EMPTY) {
                    grid_free(testGridPtr);
                    return FALSE;
                } else {
                    grid_setPoint(testGridPtr, x, y, z, id);
                }
            }
            /* Check end */
            long* lastGridPointPtr = (long*)vector_at(pointVectorPtr, j);
            grid_getPointIndices(gridPtr, lastGridPointPtr, &x, &y, &z);
            if (grid_getPoint(testGridPtr, x, y, z) != 0) {
                grid_free(testGridPtr);
                return FALSE;
            }
        } /* iteratate over pathVector */
    } /* iterate over pathVectorList */

    if (doPrintPaths) {
        puts("\nRouted Maze:");
        grid_print(testGridPtr);
    }

    grid_free(testGridPtr);

    return TRUE;
}


/* =============================================================================
 *
 * End of maze.c
 *
 * =============================================================================
 */
