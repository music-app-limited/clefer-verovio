/////////////////////////////////////////////////////////////////////////////
// Name:        editorial.h
// Author:      Laurent Pugin
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __VRV_EDITORIAL_H__
#define __VRV_EDITORIAL_H__

#include "atts_shared.h"
#include "object.h"

namespace vrv {

class Layer;
class LayerElement;
class Lem;
class Measure;
class Rdg;
class ScoreDef;
class Staff;
class StaffDef;
class StaffGrp;
    
//----------------------------------------------------------------------------
// EditorialElement
//----------------------------------------------------------------------------

/**
 * This class is a base class for the editorial element containing musical
 * content. For example <rgd> or <add>.
 * It is not an abstract class but should not be instantiated directly.
 */
class EditorialElement: public Object,
    public AttCommon
{
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method reset all attribute classes
     */
    ///@{
    EditorialElement();
    EditorialElement(std::string classid);
    virtual ~EditorialElement();
    virtual void Reset();
    ///@}

    /**
     * @name Add children to an editorial element.
     */
    ///@{
    void AddElement( LayerElement *child );
    void AddLayer( Layer *child );
    void AddMeasure( Measure *child );
    void AddScoreDef( ScoreDef *child );
    void AddStaffDef( StaffDef *child );
    void AddStaffGrp( StaffGrp *child );
    void AddStaff( Staff *child );
    ///@}
    
protected:
    
private:
    
public:
    
private:
    
};

//----------------------------------------------------------------------------
// App
//----------------------------------------------------------------------------

class App: public Object,
    public AttCommon
{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    App();
    App( EditorialLevel level );
    virtual ~App();
    virtual void Reset();
    virtual std::string GetClassName( ) { return "App"; };
    ///@}
    
    /** Getter for level **/
    EditorialLevel GetLevel() { return m_level; };
    
    /**
     * Add children to a apparatus.
     * Tests if lemOrRdg is Lem or Rdg.
     */
    void AddLemOrRdg(EditorialElement *lemOrRdg);
    
protected:
    /** We store the level of the <app> for integrity check */
    EditorialLevel m_level;

private:
    
public:
    
private:

};
    
//----------------------------------------------------------------------------
// Lem
//----------------------------------------------------------------------------

class Lem: public EditorialElement
{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    Lem();
    virtual ~Lem();
    virtual void Reset();
    virtual std::string GetClassName( ) { return "Lem"; };
    ///@}
    
protected:
    
private:
    
public:
    
private:
    
};

//----------------------------------------------------------------------------
// Rdg
//----------------------------------------------------------------------------

class Rdg: public EditorialElement
{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    Rdg();
    virtual ~Rdg();
    virtual void Reset();
    virtual std::string GetClassName( ) { return "Rdg"; };
    ///@}
    
protected:
    
private:
    
public:
    
private:
    
};

} // namespace vrv    
    
#endif
