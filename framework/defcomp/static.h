/*
 * Copyright (C) 2003 Tommi Maekitalo
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * As a special exception, you may use this file as part of a free
 * software library without restriction. Specifically, if other files
 * instantiate templates or use macros or inline functions from this
 * file, or you compile this file and link it with other files to
 * produce an executable, this file does not by itself cause the
 * resulting executable to be covered by the GNU General Public
 * License. This exception does not however invalidate any other
 * reasons why the executable file might be covered by the GNU Library
 * General Public License.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef TNT_STATIC_H
#define TNT_STATIC_H

#include <tnt/component.h>
#include <tnt/componentfactory.h>

namespace tnt
{
  class MimeHandler;

  //////////////////////////////////////////////////////////////////////
  // componentdeclaration
  //
  class Static : public Component
  {
      friend class StaticFactory;

      static std::string configDocumentRoot;
      static MimeHandler* handler;

      unsigned doCall(HttpRequest& request,
        HttpReply& reply, QueryParams& qparam, bool top);

    protected:
      void setContentType(HttpRequest& request, HttpReply& reply);

    public:
      virtual unsigned topCall(HttpRequest& request,
        HttpReply& reply, QueryParams& qparam);
      virtual unsigned operator() (HttpRequest& request,
        HttpReply& reply, QueryParams& qparam);
  };

  ////////////////////////////////////////////////////////////////////////
  // factory
  //
  class StaticFactory : public ComponentFactory
  {
    public:
      StaticFactory(const std::string& componentName)
        : ComponentFactory(componentName)
        { }
      virtual Component* doCreate(const Compident& ci,
        const Urlmapper& um, Comploader& cl);
      virtual void doConfigure(const TntConfig& config);
  };

}

#endif // TNT_STATIC_H

