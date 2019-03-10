#pragma once
#include "../Game/CharInfo.h"

#include <imgui.h>

#include <d3dx9.h>

typedef unsigned int uint32_t;

class HitboxOverlay
{
public:
	HitboxOverlay() = default;
	void Update();
	void DrawOriginLine(ImVec2 screenPos);
	void DrawCollisionAreas(const CharInfo* charObj, const D3DXVECTOR2 playerWorldPos);
	float& GetMagicNumber();

private:
	void BeforeDraw();
	void Draw();
	void AfterDraw();

	D3DXVECTOR2 CalculateObjWorldPosition(const CharInfo * charObj);
	D3DXVECTOR3 CalculateScreenPosition(D3DXVECTOR3 worldPos);

	void RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f, uint32_t segments = 16);
	void RenderCircleFilled(const ImVec2& position, float radius, uint32_t color, uint32_t segments = 16);
	void RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All, float thickness = 1.0f);
	void RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All);


	ImGuiWindowFlags m_windowFlags =
		ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoInputs
		| ImGuiWindowFlags_NoBringToFrontOnFocus
		| ImGuiWindowFlags_NoFocusOnAppearing;

	float m_rectAx = 100.0f;
	float m_rectAy = 100.0f;
	float m_rectBx = 200.0f;
	float m_rectBy = 200.0f;
};
