//
// ServerSocket.cpp
//
// Library: Net
// Package: Sockets
// Module:  ServerSocket
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DBPoco/Net/ServerSocket.h"
#include "DBPoco/Net/ServerSocketImpl.h"
#include "DBPoco/Exception.h"


using DBPoco::InvalidArgumentException;


namespace DBPoco {
namespace Net {


ServerSocket::ServerSocket(): Socket(new ServerSocketImpl)
{
}


ServerSocket::ServerSocket(const Socket& socket): Socket(socket)
{
	if (!dynamic_cast<ServerSocketImpl*>(impl()))
		throw InvalidArgumentException("Cannot assign incompatible socket");
}


ServerSocket::ServerSocket(const SocketAddress& address, int backlog): Socket(new ServerSocketImpl)
{
	impl()->bind(address, true);
	impl()->listen(backlog);
}


ServerSocket::ServerSocket(DBPoco::UInt16 port, int backlog): Socket(new ServerSocketImpl)
{
	IPAddress wildcardAddr;
	SocketAddress address(wildcardAddr, port);
	impl()->bind(address, true);
	impl()->listen(backlog);
}


ServerSocket::ServerSocket(SocketImpl* pImpl, bool ignore): Socket(pImpl)
{
}


ServerSocket::~ServerSocket()
{
}


ServerSocket& ServerSocket::operator = (const Socket& socket)
{
	if (dynamic_cast<ServerSocketImpl*>(socket.impl()))
		Socket::operator = (socket);
	else
		throw InvalidArgumentException("Cannot assign incompatible socket");
	return *this;
}


void ServerSocket::bind(const SocketAddress& address, bool reuseAddress)
{
	impl()->bind(address, reuseAddress);
}


void ServerSocket::bind(const SocketAddress& address, bool reuseAddress, bool reusePort)
{
	impl()->bind(address, reuseAddress, reusePort);
}


void ServerSocket::bind(DBPoco::UInt16 port, bool reuseAddress)
{
	IPAddress wildcardAddr;
	SocketAddress address(wildcardAddr, port);
	impl()->bind(address, reuseAddress);
}


void ServerSocket::bind(DBPoco::UInt16 port, bool reuseAddress, bool reusePort)
{
	IPAddress wildcardAddr;
	SocketAddress address(wildcardAddr, port);
	impl()->bind(address, reuseAddress, reusePort);
}


void ServerSocket::bind6(const SocketAddress& address, bool reuseAddress, bool ipV6Only)
{
	impl()->bind6(address, reuseAddress, ipV6Only);
}


void ServerSocket::bind6(const SocketAddress& address, bool reuseAddress, bool reusePort, bool ipV6Only)
{
	impl()->bind6(address, reuseAddress, reusePort, ipV6Only);
}


void ServerSocket::bind6(DBPoco::UInt16 port, bool reuseAddress, bool ipV6Only)
{
#if defined(DB_POCO_HAVE_IPv6)
	IPAddress wildcardAddr(IPAddress::IPv6);
	SocketAddress address(wildcardAddr, port);
	impl()->bind6(address, reuseAddress, ipV6Only);
#else
	throw DBPoco::NotImplementedException("No IPv6 support available");
#endif // DB_POCO_HAVE_IPv6
}

	
void ServerSocket::bind6(DBPoco::UInt16 port, bool reuseAddress, bool reusePort, bool ipV6Only)
{
#if defined(DB_POCO_HAVE_IPv6)
	IPAddress wildcardAddr(IPAddress::IPv6);
	SocketAddress address(wildcardAddr, port);
	impl()->bind6(address, reuseAddress, reusePort, ipV6Only);
#else
	throw DBPoco::NotImplementedException("No IPv6 support available");
#endif // DB_POCO_HAVE_IPv6
}

	
void ServerSocket::listen(int backlog)
{
	impl()->listen(backlog);
}


StreamSocket ServerSocket::acceptConnection(SocketAddress& clientAddr)
{
	return StreamSocket(impl()->acceptConnection(clientAddr));
}


StreamSocket ServerSocket::acceptConnection()
{
	SocketAddress clientAddr;
	return StreamSocket(impl()->acceptConnection(clientAddr));
}


} } // namespace DBPoco::Net
