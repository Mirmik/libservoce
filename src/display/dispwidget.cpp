// Moved the #include <OpenGl_GraphicsDriver.hxx>
// and added 9 #undef lines to get to build in Linux
#include <OpenGl_GraphicDriver.hxx>
#undef Bool
#undef CursorShape
#undef None
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut
#undef FontChange
#undef Expose

// base header
//#include <zencad/DisplayWidget.h>

// occ header files.
/*#include <V3d_View.hxx>
#include <V3d_AmbientLight.hxx>
#include <V3d_DirectionalLight.hxx>

#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>

#include <Standard_TypeDef.hxx>

#ifdef WNT
#include <WNT_Window.hxx>
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
#include <Cocoa_Window.hxx>
#else
#include <Xw_Window.hxx>
#endif
#include <AIS_Shape.hxx>

#include <Geom_Line.hxx>
#include <Geom_Axis1Placement.hxx>
#include <AIS_Axis.hxx>
#include <IntCurvesFace_ShapeIntersector.hxx>

#include <servoce/display.h>
#include <local/display.h>
#include <local/util.h>

static Handle(Graphic3d_GraphicDriver)& GetGraphicDriver()
{
    static Handle(Graphic3d_GraphicDriver) aGraphicDriver;
    return aGraphicDriver;
}

const Handle_AIS_InteractiveContext& servoce::disp::DisplayWidget::getContext() const
{
    return m_context;
}

void servoce::disp::DisplayWidget::showEvent(QShowEvent* e)
{
    QWidget::showEvent(e);
    //init();
    //m_view->MustBeResized();
    //m_view->Redraw();
}

void servoce::disp::DisplayWidget::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);

    if (m_context.IsNull())
    {
        init();

        //for (auto& shp : scn->)
        //{
        //    m_context->Display (shp->native(), false);
        //}

        auto axX = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(1, 0, 0)));
        auto axY = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(0, 1, 0)));
        auto axZ = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(0, 0, 1)));

        axX->SetColor(Quantity_NOC_RED);
        axY->SetColor(Quantity_NOC_GREEN);
        axZ->SetColor(Quantity_NOC_BLUE1);

        getContext()->Display(axX, false);
        getContext()->Display(axY, false);
        getContext()->Display(axZ, false);
        autoscale();
    }

    m_view->Redraw();
}

void servoce::disp::DisplayWidget::autoscale()
{
    m_view->FitAll (0.5, false);
}

void servoce::disp::DisplayWidget::orient1()
{
    orient = 1;
    m_view->ResetViewOrientation();
    autoscale();
}

void servoce::disp::DisplayWidget::orient2()
{
    orient = 2;
    m_view->ResetViewOrientation();
    autoscale();
}

void servoce::disp::DisplayWidget::resizeEvent(QResizeEvent* e)
{
    Q_UNUSED(e);

    if ( !m_view.IsNull() )
    {
        m_view->MustBeResized();
    }
}

void servoce::disp::DisplayWidget::init()
{
    setMouseTracking(true);
    Handle(Aspect_DisplayConnection) aDisplayConnection = new Aspect_DisplayConnection();

    if (GetGraphicDriver().IsNull())
    {
        GetGraphicDriver() = new OpenGl_GraphicDriver(aDisplayConnection);
    }

    WId window_handle = (WId) winId();

#ifdef WNT
    Handle(WNT_Window) wind = new WNT_Window((Aspect_Handle) window_handle);
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
    Handle(Cocoa_Window) wind = new Cocoa_Window((NSView *) window_handle);
#else
    Handle(Xw_Window) wind = new Xw_Window(aDisplayConnection, (Window) window_handle);
#endif

    m_viewer = new V3d_Viewer(GetGraphicDriver());
    m_viewer->SetDefaultLights();
    m_viewer->SetLightOn();

    m_view = m_viewer->CreateView();
    m_view->SetBgGradientColors(
        Quantity_Color(0.5, 0.5, 0.5, Quantity_TOC_RGB),
        Quantity_Color(0.3, 0.3, 0.3, Quantity_TOC_RGB),
        Aspect_GFM_VER,
        Standard_True
    );

    m_view->SetWindow(wind);
    if (!wind->IsMapped()) wind->Map();

    m_context = new AIS_InteractiveContext(m_viewer);
    m_context->DefaultDrawer ()->SetFaceBoundaryDraw(true);

    m_view->MustBeResized();
    m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);

    m_context->SetDisplayMode(AIS_Shaded, false);
}


void servoce::disp::DisplayWidget::onMouseWheel( const int theFlags, const int theDelta, const QPoint thePoint )
{
    Q_UNUSED(theFlags);

    Standard_Integer aFactor = 16;

    Standard_Integer aX = thePoint.x();
    Standard_Integer aY = thePoint.y();

    if (theDelta > 0)
    {
        aX += aFactor;
        aY += aFactor;
    }
    else
    {
        aX -= aFactor;
        aY -= aFactor;
    }

    m_view->Zoom(thePoint.x(), thePoint.y(), aX, aY);
}

void servoce::disp::DisplayWidget::onLButtonDown( const int theFlags, const QPoint thePoint )
{
    Q_UNUSED(theFlags);
    m_view->StartRotation(thePoint.x(), thePoint.y(), 1);
    temporary1 = thePoint;
}

void servoce::disp::DisplayWidget::onMButtonDown( const int theFlags, const QPoint thePoint )
{
    Q_UNUSED(theFlags);
    temporary1 = thePoint;
}

void servoce::disp::DisplayWidget::onRButtonDown( const int theFlags, const QPoint thePoint )
{
    Q_UNUSED(theFlags);
    temporary1 = thePoint;
}

void servoce::disp::DisplayWidget::onLButtonUp( const int theFlags, const QPoint thePoint )
{
}

void servoce::disp::DisplayWidget::onMButtonUp( const int theFlags, const QPoint thePoint )
{
}

void servoce::disp::DisplayWidget::onRButtonUp( const int theFlags, const QPoint thePoint )
{
}

void servoce::disp::DisplayWidget::onMouseMove( const int theFlags, const QPoint thePoint )
{

    getMousePositionWithObjects(thePoint);

    QPoint mv = thePoint - temporary1;
    temporary1 = thePoint;

    if (orient == 1)
    {
        if (theFlags & Qt::LeftButton)
        {
            phi -= mv.x() * 0.01;
            psi += mv.y() * 0.01;
            m_view->SetProj(cos(psi) * cos(phi), cos(psi) * sin(phi), sin(psi));
        }

        if (theFlags & Qt::RightButton)
        {
            m_view->Pan(mv.x(), -mv.y());
        }
    }

    if (orient == 2)
    {
        if (theFlags & Qt::LeftButton)
        {
            m_view->Rotation(thePoint.x(), thePoint.y());
            double Vx;
            double Vy;
            double Vz;
            m_view->Proj(Vx, Vy, Vz);
        }

        if (theFlags & Qt::RightButton)
        {
            m_view->Pan(mv.x(), -mv.y());
        }
    }
}

gp_Lin createLineFromViewEye(Standard_Real x, Standard_Real y, Handle(V3d_View) view)
{
    Standard_Real Xp = x, Yp = y;
    Standard_Real Xv, Yv, Zv;
    Standard_Real Vx, Vy, Vz;

    view->Convert( Xp, Yp, Xv, Yv, Zv );
    view->Proj( Vx, Vy, Vz );

    return gp_Lin(gp_Pnt(Xv, Yv, Zv), gp_Dir(Vx, Vy, Vz));
}

gp_Pnt servoce::disp::DisplayWidget::getMousePositionWithObjects(const QPoint point)
{
    auto selector = m_context->MainSelector();
    selector->Pick(point.x(), point.y(), m_view);

    const Standard_Integer aDetectedNb = selector->NbPicked();

    auto viewLine = createLineFromViewEye(point.x(), point.y(), m_view);

    for (Standard_Integer aDetIter = 1; aDetIter <= aDetectedNb; ++aDetIter)
    {
        Handle(SelectMgr_EntityOwner) anOwner = selector->Picked(aDetIter);

        Handle(AIS_InteractiveObject) anObj
            = Handle(AIS_InteractiveObject)::DownCast (anOwner->Selectable());

        if (anObj->Type() != AIS_KOI_Shape) {
            continue;
        }

        Handle_AIS_Shape hShape = Handle_AIS_Shape::DownCast(anObj);
        const TopoDS_Shape &shape = hShape->Shape();

        gp_Pnt ip;

        IntCurvesFace_ShapeIntersector shapeIntersector;
        shapeIntersector.Load(shape, Precision::Confusion());
        shapeIntersector.Perform(viewLine, -RealLast(), RealLast());

        if (shapeIntersector.NbPnt() >= 1) {
            ip = shapeIntersector.Pnt(1);
        } else {
            continue;
        }

        break;
    }
}
*/