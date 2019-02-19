/**
 * @file Render.c
 * @ingroup Render
 * @defgroup Render
 * @author Michael Fitzmayer
 * @copyright "THE BEER-WARE LICENCE" (Revision 42)
 */

#include <SDL.h>
#include <eszfw.h>
#include "Render.h"
#include "Resources.h"

Sint8 Render(Res *pstRes)
{
    Sint8 s8ReturnValue = 0;

    s8ReturnValue = DrawBackground(
        pstRes->pstEntity[0]->eDirection,
        pstRes->pstVideo->s32LogicalWindowHeight,
        pstRes->pstCamera->dPosY,
        pstRes->dBgVelocityX,
        pstRes->pstVideo->pstRenderer,
        pstRes->pstBg);

    for (Uint8 u8Index = 1; u8Index <= 3; u8Index++)
    {
        s8ReturnValue = DrawEntity(
            pstRes->pstEntity[u8Index],
            pstRes->pstCamera,
            pstRes->pstSpVehicles,
            pstRes->pstVideo->pstRenderer);
    }

    s8ReturnValue = DrawMap(
        0, 1, 1, "BG",
        pstRes->pstCamera->dPosX,
        pstRes->pstCamera->dPosY,
        pstRes->pstMap,
        pstRes->pstVideo->pstRenderer);

    s8ReturnValue = DrawEntity(
        pstRes->pstEntity[0],
        pstRes->pstCamera,
        pstRes->pstSpPlayer,
        pstRes->pstVideo->pstRenderer);

    s8ReturnValue = DrawMap(
        1, 0, 0, "FG",
        pstRes->pstCamera->dPosX,
        pstRes->pstCamera->dPosY,
        pstRes->pstMap,
        pstRes->pstVideo->pstRenderer);

    RenderScene(pstRes->pstVideo);
    return s8ReturnValue;
}