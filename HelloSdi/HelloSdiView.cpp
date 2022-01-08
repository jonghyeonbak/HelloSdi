
// HelloSdiView.cpp : CHelloSdiView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HelloSdi.h"
#endif

#include "HelloSdiDoc.h"
#include "HelloSdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloSdiView

IMPLEMENT_DYNCREATE(CHelloSdiView, CEditView)

BEGIN_MESSAGE_MAP(CHelloSdiView, CEditView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
		ON_WM_CREATE()
END_MESSAGE_MAP()

// CHelloSdiView 생성/소멸

CHelloSdiView::CHelloSdiView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHelloSdiView::~CHelloSdiView()
{
}

BOOL CHelloSdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 자동 줄바꿈을 사용합니다.

	return bPreCreated;
}


// CHelloSdiView 인쇄

BOOL CHelloSdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 CEditView 준비
	return CEditView::OnPreparePrinting(pInfo);
}

void CHelloSdiView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 기본 CEditView 시작 인쇄
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CHelloSdiView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 기본 CEditView 종료 인쇄
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CHelloSdiView 진단

#ifdef _DEBUG
void CHelloSdiView::AssertValid() const
{
	CEditView::AssertValid();
}

void CHelloSdiView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CHelloSdiDoc* CHelloSdiView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloSdiDoc)));
	return (CHelloSdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloSdiView 메시지 처리기


int CHelloSdiView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
		if (CEditView::OnCreate(lpCreateStruct) == -1)
				return -1;

		// TODO:  여기에 특수화된 작성 코드를 추가합니다.

		return 0;
}

