
#include "texRenderTarget.h"

void texRenderTarget::initialize_()
{
	glGenFramebuffers(1, &framebuffer_);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_);

	glGenTextures(1, &texcolorbuffer_);
	glBindTexture(GL_TEXTURE_2D, texcolorbuffer_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texcolorbuffer_, 0);

	glGenRenderbuffers(1, &renderbuffer_);
	glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer_);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderbuffer_);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		fprintf(stdout, "Generating offscreen framebuffer failed! Code: %d\n", glCheckFramebufferStatus(GL_FRAMEBUFFER));
	}
	else
	{
		fprintf(stdout, "Generated offscreen framebuffer with id: %d\n", framebuffer_);
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}