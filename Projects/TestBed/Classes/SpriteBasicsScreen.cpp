/*==================================================================================
    Copyright (c) 2008, DAVA Consulting, LLC
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of the DAVA Consulting, LLC nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE DAVA CONSULTING, LLC AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL DAVA CONSULTING, LLC BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    Revision History:
        * Created by Vitaliy Borodovsky 
=====================================================================================*/
#include "SpriteBasicsScreen.h"
#include "TouchEffectsControl.h"

void SpriteBasicsScreen::LoadResources()
{
	redSprite = Sprite::Create("~res:/Gfx/SpriteBasics/redsprite");
	greenSprite = Sprite::Create("~res:/Gfx/SpriteBasics/greensprite");
	blueSprite = Sprite::Create("~res:/Gfx/SpriteBasics/bluesprite");
	tranclucentSprite = Sprite::Create("~res:/Gfx/SpriteBasics/transclucentsprite");
	zebraSprite = Sprite::Create("~res:/Gfx/SpriteBasics/zebrasprite");
	
	graphicsFont = GraphicsFont::Create("~res:/Fonts/bd_cartoon.def", "~res:/Gfx/Fonts2/bd_cartoon");
	graphicsFont2 = GraphicsFont::Create("~res:/Fonts/jointby.def", "~res:/Gfx/Fonts2/jointby");
// 	button = new UIButton(Rect(200, 200, 100, 50));
// 	//button->SetDebugDraw(true);
// 	button->SetStateDrawType(UIControl::STATE_NORMAL|UIControl::STATE_HOVER|UIControl::STATE_PRESSED_INSIDE, UIControlBackground::DRAW_FILL);
// 	button->GetStateBackground(UIControl::STATE_NORMAL)->color = Color(0, 0.4, 0, 1.0);
// 	button->GetStateBackground(UIControl::STATE_HOVER)->color = Color(0, 0.8, 0, 1.0);
// 	button->GetStateBackground(UIControl::STATE_PRESSED_INSIDE)->color = Color(0.6, 1.0, 0.6, 1.0);
// 	AddControl(button);
// 
// 	button->AddEvent(UIControl::EVENT_TOUCH_UP_INSIDE, Message(this, &SpriteBasicsScreen::OnButtonPressed));
	uint32 fh = graphicsFont->GetFontHeight();
	Logger::Debug("font height: %d", fh); 

}

void SpriteBasicsScreen::UnloadResources()
{
	SafeRelease(graphicsFont);
	SafeRelease(graphicsFont2);
	SafeRelease(redSprite);
	SafeRelease(greenSprite);
	SafeRelease(blueSprite);
	SafeRelease(tranclucentSprite);
	SafeRelease(zebraSprite);
}

void SpriteBasicsScreen::WillAppear()
{
	AddControl(new TouchEffectsControl());
}

void SpriteBasicsScreen::WillDisappear()
{
	
}

void SpriteBasicsScreen::Input(UIEvent * touch)
{
	if ((touch->phase == UIEvent::PHASE_ENDED) && (touch->tid == UIEvent::BUTTON_2))
	{
		Core::Instance()->ToggleFullscreen();
	}
}

void SpriteBasicsScreen::Draw(const UIGeometricData &geometricData)
{
	//Logger::Debug("SpriteBasicsScreen::Draw");
	//RenderManager::Instance()->ClipPush();
	//RenderManager::Instance()->SetClip(Rect(20, 30, 890, 650));

#if 0 // BASIC TESTS OF DIFFERENT TYPES OF SPRITES
// 	RenderManager::Instance()->ClearWithColor(0, 0.3f, 0.0f, 1.0f);
// 	RenderManager::Instance()->SetBlendMode(BLEND_ONE, BLEND_ONE_MINUS_SRC_ALPHA);
// 	redSprite->SetPosition(0, 0);
// 	redSprite->Draw();
// 	
// 	greenSprite->SetPosition(50, 0);
// 	greenSprite->Draw();
// 	
// 	blueSprite->SetPosition(100, 0);
// 	blueSprite->Draw();
// 	
// 	blueSprite->SetPosition(Core::Instance()->GetVirtualScreenWidth() - blueSprite->GetWidth(), 0);
// 	blueSprite->Draw();
// 
// 	tranclucentSprite->SetPosition(Core::Instance()->GetVirtualScreenWidth() - blueSprite->GetWidth(), Core::Instance()->GetVirtualScreenHeight() - blueSprite->GetHeight());
// 	tranclucentSprite->Draw();
// 
// 	zebraSprite->SetPosition(0, Core::Instance()->GetVirtualScreenHeight() - blueSprite->GetHeight());
// 	zebraSprite->Draw();
// 
// 	RenderManager::Instance()->SetColor(1.0f, 1.0f, 1.0f, 0.5f);
// 	redSprite->SetPosition(0, 50);
// 	redSprite->Draw();
// 
// 	greenSprite->SetPosition(50, 50);
// 	greenSprite->Draw();
// 
// 	blueSprite->SetPosition(100, 50);
// 	blueSprite->Draw();
	
	
	Logger::Debug("vtof: %f", Core::GetVirtualToPhysicalFactor());

	RenderManager::Instance()->SetColor(1.0f, 0.0f, 1.0f, 0.5f);
	RenderManager::Instance()->FillRect(Rect(100, 100, 40, 40));
#else
	zebraSprite->Reset();
	zebraSprite->SetPosition(0.0f, 30.0f);
	zebraSprite->Draw();
	
	zebraSprite->Reset();
	zebraSprite->SetPosition(50.0f, 30.0f);
	zebraSprite->SetScale(0.5f, 0.5f);
	zebraSprite->Draw();
	
	zebraSprite->Reset();
	zebraSprite->SetPosition(100.0f, 30.0f);
	zebraSprite->SetScale(1.2f, 1.2f);
	zebraSprite->Draw();
	
	zebraSprite->Reset();
	zebraSprite->SetPosition(150.0f, 30.0f);
	zebraSprite->SetAngle(DegToRad(90.0f));
	zebraSprite->Draw();
	
	zebraSprite->Reset();
	zebraSprite->SetPosition(200.0f, 30.0f);
	zebraSprite->SetPivotPoint(zebraSprite->GetWidth() / 2.0f, zebraSprite->GetHeight() / 2.0f);
	zebraSprite->SetAngle(DegToRad(90.0f));
	zebraSprite->Draw();
	
	Sprite::DrawState drawState;
	
	drawState.Reset();
	drawState.SetPosition(0.0f, 130.0f);
	zebraSprite->Draw(&drawState);
	
	drawState.Reset();
	drawState.SetPosition(50.0f, 130.0f);
	drawState.SetScale(0.5f, 0.5f);
	zebraSprite->Draw(&drawState);
	
	drawState.Reset();
	drawState.SetPosition(100.0f, 130.0f);
	drawState.SetScale(1.2f, 1.2f);
	zebraSprite->Draw(&drawState);
	
	drawState.Reset();
	drawState.SetPosition(150.0f, 130.0f);
	drawState.SetAngle(DegToRad(90.0f));
	zebraSprite->Draw(&drawState);
	
	drawState.Reset();
	drawState.SetPosition(200.0f, 130.0f);
	drawState.SetPivotPoint(zebraSprite->GetWidth() / 2.0f, zebraSprite->GetHeight() / 2.0f);
	drawState.SetAngle(DegToRad(90.0f));
	zebraSprite->Draw(&drawState);
	
	/*
	spriteFont->SetPosition(50, 50);
	spriteFont->SetFrame(32);
	spriteFont->Draw();
	
	spriteFont->SetPosition(65, 50);
	spriteFont->SetFrame(33);
	spriteFont->Draw();

	spriteFont->SetPosition(85, 50);
	spriteFont->SetFrame(34 );
	spriteFont->Draw();
	 */
	
	WideString s = L"Super mega font number #1";
	Size2i size = graphicsFont->GetStringSize(s);
	
	RenderManager::Instance()->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	RenderManager::Instance()->DrawRect(Rect(10, 200, size.dx, size.dy));
	
	RenderManager::Instance()->SetColor(0.0f, 0.0f, 1.0f, 1.0f);
	RenderManager::Instance()->DrawLine(Vector2(10, 200), 
										Vector2(10 + size.dx, 200));
	graphicsFont->DrawString(10, 200, L"Super mega font number #1");
	graphicsFont->DrawString(10, 200 + graphicsFont->GetFontHeight(), L"String number 2");
	
	
	size = graphicsFont2->GetStringSize(s);
	
	RenderManager::Instance()->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	RenderManager::Instance()->DrawRect(Rect(10, 300, size.dx, size.dy));
	RenderManager::Instance()->SetColor(0.0f, 0.0f, 1.0f, 1.0f);
	RenderManager::Instance()->DrawLine(Vector2(10, 300), 
										Vector2(10 + size.dx, 300));
	
	RenderManager::Instance()->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	graphicsFont2->DrawString(10, 300, s);
	graphicsFont2->DrawString(10, 300 + graphicsFont->GetFontHeight(), L"String number 2");
#endif 
	
	//RenderManager::Instance()->ClipPop();
}

void SpriteBasicsScreen::OnButtonPressed( BaseObject * owner, void * userData, void * callerData )
{
	/* 
	UIMoveInTransition * moveInTransition = new UIMoveInTransition();
	//moveInTransition->SetDuration(3.0f);
	moveInTransition->SetType(UIMoveInTransition::FROM_LEFT, true);
	UIScreenManager::Instance()->SetScreen(SCREEN_CLIP_TEST, moveInTransition);
	SafeRelease(moveInTransition);*/

	// 	Rect r = button->GetRect();
	// 	r.x += 100;
	// 	r.y += 100;
	// 	button->MoveAnimation(r, 1.0f, Interpolation::EASY_IN_EASY_OUT);
	//button->ScaleAnimation(Vector2(1.3f, 1.3f), 0.3f, Interpolation::EASY_IN);
	//button->ScaleAnimation(Vector2(1 / 1.3f, 1 / 1.3f), 0.3f, Interpolation::LINEAR);


}