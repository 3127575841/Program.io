// 页面加载完成后执行
document.addEventListener('DOMContentLoaded', function() {
    // 添加no-transition类到body，禁用所有过渡效果
    document.body.classList.add('no-transition');
    
    // 启动轮播图
    initSlider();
    
    // 设置技能条动画
    initSkillBars();
    
    // 设置联系表单验证
    initContactForm();
    
    // 页面加载完成后，移除no-transition类，启用过渡效果
    setTimeout(function() {
        document.body.classList.remove('no-transition');
    }, 300);
    
    // 平滑滚动
    initSmoothScroll();
});

// 初始化轮播图
function initSlider() {
    const slides = document.querySelectorAll('.slide');
    const dots = document.querySelectorAll('.dot');
    const prevBtn = document.querySelector('.prev-btn');
    const nextBtn = document.querySelector('.next-btn');
    let currentIndex = 0;
    let interval;
    
    // 自动轮播
    function startAutoSlide() {
        interval = setInterval(() => {
            changeSlide(currentIndex + 1);
        }, 5000); // 每5秒切换一次
    }
    
    // 停止自动轮播
    function stopAutoSlide() {
        clearInterval(interval);
    }
    
    // 切换轮播图
    function changeSlide(index) {
        // 隐藏当前轮播图
        slides[currentIndex].classList.remove('active');
        dots[currentIndex].classList.remove('active');
        
        // 更新索引
        currentIndex = index;
        if (currentIndex >= slides.length) {
            currentIndex = 0;
        } else if (currentIndex < 0) {
            currentIndex = slides.length - 1;
        }
        
        // 显示新的轮播图
        slides[currentIndex].classList.add('active');
        dots[currentIndex].classList.add('active');
    }
    
    // 点击上一张
    prevBtn.addEventListener('click', () => {
        stopAutoSlide();
        changeSlide(currentIndex - 1);
        startAutoSlide();
    });
    
    // 点击下一张
    nextBtn.addEventListener('click', () => {
        stopAutoSlide();
        changeSlide(currentIndex + 1);
        startAutoSlide();
    });
    
    // 点击指示点
    dots.forEach((dot, index) => {
        dot.addEventListener('click', () => {
            stopAutoSlide();
            changeSlide(index);
            startAutoSlide();
        });
    });
    
    // 开始自动轮播
    startAutoSlide();
}

// 初始化技能条动画
function initSkillBars() {
    const skillLevels = document.querySelectorAll('.skill-level');
    
    // 监听滚动事件
    window.addEventListener('scroll', function() {
        const skillsSection = document.querySelector('.skills');
        if (!skillsSection) return;
        
        const sectionTop = skillsSection.getBoundingClientRect().top;
        const windowHeight = window.innerHeight;
        
        // 当技能部分进入视口时，开始动画
        if (sectionTop < windowHeight * 0.8) {
            skillLevels.forEach(skill => {
                // 获取技能值（宽度百分比）
                const width = skill.style.width;
                // 先设置为0，然后通过CSS过渡动画到目标宽度
                skill.style.width = '0';
                
                setTimeout(() => {
                    skill.style.width = width;
                }, 100);
            });
            
            // 移除滚动监听，防止重复触发
            window.removeEventListener('scroll', arguments.callee);
        }
    });
}

// 初始化联系表单验证
function initContactForm() {
    const contactForm = document.getElementById('contact-form');
    if (!contactForm) return;
    
    contactForm.addEventListener('submit', function(e) {
        e.preventDefault();
        
        // 获取表单字段
        const name = document.getElementById('name').value.trim();
        const email = document.getElementById('email').value.trim();
        const message = document.getElementById('message').value.trim();
        
        // 简单验证
        if (name === '') {
            alert('请输入您的姓名');
            return;
        }
        
        if (email === '') {
            alert('请输入您的邮箱');
            return;
        }
        
        if (!isValidEmail(email)) {
            alert('请输入有效的邮箱地址');
            return;
        }
        
        if (message === '') {
            alert('请输入您的留言');
            return;
        }
        
        // 验证通过
        alert('提交成功！我们会尽快回复您。');
        contactForm.reset();
    });
    
    // 验证邮箱格式
    function isValidEmail(email) {
        const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return regex.test(email);
    }
}

// 平滑滚动
function initSmoothScroll() {
    const navLinks = document.querySelectorAll('.nav-menu a');
    
    navLinks.forEach(link => {
        link.addEventListener('click', function(e) {
            // 获取目标锚点
            const targetId = this.getAttribute('href');
            if (targetId.startsWith('#') && targetId !== '#') {
                e.preventDefault();
                
                // 获取目标元素
                const targetElement = document.querySelector(targetId);
                if (targetElement) {
                    // 计算偏移位置
                    const headerHeight = document.querySelector('.header').offsetHeight;
                    const targetPosition = targetElement.getBoundingClientRect().top + window.pageYOffset - headerHeight;
                    
                    // 平滑滚动
                    window.scrollTo({
                        top: targetPosition,
                        behavior: 'smooth'
                    });
                    
                    // 更新活动链接
                    navLinks.forEach(navLink => {
                        navLink.classList.remove('active');
                    });
                    this.classList.add('active');
                }
            }
        });
    });
}

// 图片下载功能（仅在管理页面使用）
async function downloadImage(imageSrc, fileName) {
    try {
        const image = await fetch(imageSrc);
        const imageBlob = await image.blob();
        const imageURL = URL.createObjectURL(imageBlob);

        const link = document.createElement('a');
        link.href = imageURL;
        link.download = fileName;
        document.body.appendChild(link);
        link.click();
        document.body.removeChild(link);
    } catch (error) {
        console.error('下载图片失败:', error);
    }
}

// 用于管理员下载示例图片的函数
function downloadAlgorithmImages() {
    // 算法相关图片URL
    const algorithmImages = [
        {
            url: 'https://source.unsplash.com/random/800x400/?algorithm,code',
            fileName: 'banner1.jpg'
        },
        {
            url: 'https://source.unsplash.com/random/800x400/?programming,computer',
            fileName: 'banner2.jpg'
        },
        {
            url: 'https://source.unsplash.com/random/800x400/?technology,exam',
            fileName: 'banner3.jpg'
        },
        {
            url: 'https://source.unsplash.com/random/300x200/?sorting,algorithm',
            fileName: 'sort.jpg'
        },
        {
            url: 'https://source.unsplash.com/random/300x200/?search,algorithm',
            fileName: 'search.jpg'
        },
        {
            url: 'https://source.unsplash.com/random/300x200/?dynamic,programming',
            fileName: 'dynamic.jpg'
        }
    ];

    // 下载所有图片
    algorithmImages.forEach(img => {
        downloadImage(img.url, img.fileName);
    });
}
