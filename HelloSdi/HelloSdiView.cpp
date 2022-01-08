
// HelloSdiView.cpp : CHelloSdiView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
		ON_WM_CREATE()
END_MESSAGE_MAP()

// CHelloSdiView ����/�Ҹ�

CHelloSdiView::CHelloSdiView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CHelloSdiView::~CHelloSdiView()
{
}

BOOL CHelloSdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// �ڵ� �ٹٲ��� ����մϴ�.

	return bPreCreated;
}


// CHelloSdiView �μ�

BOOL CHelloSdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� CEditView �غ�
	return CEditView::OnPreparePrinting(pInfo);
}

void CHelloSdiView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// �⺻ CEditView ���� �μ�
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CHelloSdiView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// �⺻ CEditView ���� �μ�
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CHelloSdiView ����

#ifdef _DEBUG
void CHelloSdiView::AssertValid() const
{
	CEditView::AssertValid();
}

void CHelloSdiView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CHelloSdiDoc* CHelloSdiView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloSdiDoc)));
	return (CHelloSdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloSdiView �޽��� ó����


int CHelloSdiView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
		if (CEditView::OnCreate(lpCreateStruct) == -1)
				return -1;

		// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

		return 0;
}

